#include "./hex_game.h"


// the constructor initializes a new game and starts playing
HexGame::HexGame() {
  std::vector<char*> board_symbols;

  // create the two players
  this->_players.create_player("player1", player_type::HUMAN);
  this->_players.create_player("player2", player_type::HUMAN);

  // ask who gets the first move
  // the one who gets the first move will be the first element in the vector 
  if (AsciiArt::ask_user("who gets the first move?", 
        this->_players.get_all_player_names()) == 1) {

    // the other player should move first
    this->_players.swap_player_position();
  }

  // let player choose a board size out of _board_choices
  this->_board_size = this->_board_choices[
    AsciiArt::ask_user("choose the board size:",

      // procuce a vector of strings, each string is a choice of a board size
      std::accumulate(
        this->_board_choices.begin(), this->_board_choices.end(),
        std::vector<std::string>(),
        [](std::vector< std::string >& v, int choice) {
        
          // concatenate the board sizes into a pretty format:
          // "([0-9]+)x([0-9]+)"
          v.push_back(std::to_string(choice) + "x" + std::to_string(choice));
          return v;
        }
      )
    )
  ];

  // create an EdgeGraph for each of the two players
  this->_edge_graphs.resize(2);
  this->_edge_graphs[0] = new EdgeGraph();
  this->_edge_graphs[1] = new EdgeGraph();

  // vectors of board fields and symbols according to the chosen board size
  this->_fields.resize(pow(this->_board_size, 2));
  board_symbols.resize(pow(this->_board_size, 2));

  // create a list of pointers to the symbols of each field on the board
  std::transform (this->_fields.begin(), this->_fields.end(),
      board_symbols.begin(), [] (Field& f) { return f.get_symref(); });

  // this creates two virtual fields for each player that are
  // used to check if a player has a path across the board
  this->_create_player_src_dst_nodes();

  // welcome banner and symbol legend
  AsciiArt::banner(
    std::make_tuple(
      this->_players.get_name(0),
      this->_players.get_symbol(0),
      direction_string.at(board_direction::WEST_EAST)
    ),
    std::make_tuple(
      this->_players.get_name(1),
      this->_players.get_symbol(1),
      direction_string.at(board_direction::NORTH_SOUTH)
    )
  );

  // keep playing until we have a winner
  while (true) {

    // print the whole current board
    AsciiArt::print_board(board_symbols, this->_board_size);

    // ask player for the next move
    std::cout << this->_players.get_name(this->_players.get_active_id())
      << "'s turn:" << std::endl;

    // retry until the move is valid
    while (!this->_next_move()) {
      std::cout << "illegal move, try again" << std::endl;
    }

    // break if a player has won the game
    if (this->_edge_graphs[this->_players.get_active_id()]
          ->fields_are_connected(
            this->_players.get_src_dst_nodes(
              this->_players.get_active_id()
      )))
      break;

    // swap players because it's the other one's turn
    this->_players.swap_active();
  }

  // print some nice banner for the winner
  AsciiArt::announce_winner(
      this->_players.get_name(this->_players.get_active_id()));
  AsciiArt::print_board(board_symbols, this->_board_size);
}


HexGame::~HexGame() {
  delete this->_edge_graphs[0];
  delete this->_edge_graphs[1];
}


// retrieve the next move from player and execute it
bool HexGame::_next_move() {
  std::list<int> adjacent_fields;
  int field;

  // retreive the next move from currently active Player object
  std::pair<int, int> move = this->_players.get_move();

  // do some checks to verify if the move is valid
  if (!this->_verify_move(move, field))
    return false;

  // update the board field
  this->_fields[field].use_field(
      this->_players.get_active_id(),
      this->_players.get_symbol());

  // get all fields on the board that are adjacent to the given field
  HexBoard::get_adjacent_fields(field, this->_board_size, adjacent_fields);

  // remove fields from adjacent_fields that do not belong to current player
  adjacent_fields.remove_if(
    [&](int i) {
      return this->_fields[i].get_owner() != this->_players.get_active_id();
    }
  );

  // add edges to all fields that are adjacent and belong to current player
  this->_edge_graphs[this->_players.get_active_id()]
    ->add_edges(field, adjacent_fields);

  // print the move to the console with some ascii art
  AsciiArt::print_players_move(this->_players.get_name(), move);

  return true;
}


// do a bunch of checks to verify if a given move is ok
bool HexGame::_verify_move(std::pair<int, int>& m, int& field) {

  // check if given values are in valid range
  if (m.first >= this->_board_size || m.second >= this->_board_size)
    return false;
  if (m.first < 0 || m.second < 0)
    return false;

  // convert two dimensional coordinates into field number
  field = m.second * this->_board_size + m.first;

  // more move validation
  if ((field < 0) || (field >= pow(this->_board_size, 2)))
    return false;

  // check if field is still empty
  if (!this->_fields[field].is_empty())
    return false;

  // all checks ok
  return true; 
}


// creates 4 virtual nodes that don't exist on the board, one per edge of the
// board. each of them has edges to all fields on the corresponding edge of the
// board. they are used to easily test if a path from one edge of the board to
// the opposing edge has been built.
void HexGame::_create_player_src_dst_nodes() {

  // set the starting number of the virtual nodes
  this->_players.set_virtual_start(pow(this->_board_size, 2) + 1);

  for (int i = 0; i <= 1; ++i) {
    std::pair< std::vector<int>, std::vector<int> > board_edge_nodes;
    board_direction dir;
    std::pair<int, int> src_dst_nodes = this->_players.get_src_dst_nodes(i);

    // the first player always plays west <-> east, the second north <-> south
    if (i == 0) {
      dir = board_direction::WEST_EAST;
    } else {
      dir = board_direction::NORTH_SOUTH;
    }

    // get all fields on the two opposite sides of the board that the current
    // player has to connect. store them into board_edge_nodes.
    HexBoard::get_board_edge_fields(
      this->_board_size, dir, board_edge_nodes
    );

    // connect nodes of one board edge to one of the players virtual nodes
    for (auto j: board_edge_nodes.first)
      this->_edge_graphs[i]->add_edge(j, src_dst_nodes.first);

    // connect nodes of other board edge to the players other virtual node
    for (auto j: board_edge_nodes.second)
      this->_edge_graphs[i]->add_edge(j, src_dst_nodes.second);
  }
}
