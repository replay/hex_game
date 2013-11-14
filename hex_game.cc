#include "./hex_game.h"

HexGame::HexGame() {
  Player* player;
  std::vector<char*> board_symbols;

  // two players and one edge graph for each of them
  this->_players.resize(2);

  this->_players[0] = new HumanPlayer(1, "player1", 'X');
  this->_players[1] = new HumanPlayer(2, "player2", 'O');

  // create an EdgeGraph for each player
  for (auto p: this->_players)
    this->_player_data[p->get_id()].first = new EdgeGraph(this->_board_size);

  // ask who gets the first move
  // the one who gets the first move will be the first element in the vector 
  if (AsciiArt::ask_user("who gets the first move?", 
        std::accumulate(
          this->_players.begin(), this->_players.end(),
          std::vector<std::string>(), [](std::vector<std::string>& v, Player* p) {
            v.push_back(p->get_name());
            return v;
          }
        )
      ) == 2) {
    player = this->_players[0];
    this->_players[0] = this->_players[1];
    this->_players[1] = player;
  }

  // current player is the first one, will be swapped before first input
  player = this->_players[1];

  // set the playing direction for each of the two players
  this->_player_data[this->_players[0]->get_id()].second = board_direction::WEST_EAST;
  this->_player_data[this->_players[1]->get_id()].second = board_direction::NORTH_SOUTH;

  // let player choose a board size out of _board_choices, store the result in _board_size
  this->_board_size = this->_board_choices[
    AsciiArt::ask_user("choose the board size:",
      std::accumulate(
        this->_board_choices.begin(), this->_board_choices.end(),
        std::vector<std::string>(), [](std::vector< std::string >& v, int choice) {
          v.push_back(std::to_string(choice) + "x" + std::to_string(choice));
          return v;
        }
      )
    )
  ];

  this->_fields.resize(this->_board_size * this->_board_size);
  board_symbols.resize(this->_board_size * this->_board_size);

  // create a list of pointers to the symbols of each field on the board
  std::transform (this->_fields.begin(), this->_fields.end(),
      board_symbols.begin(), [] (Field& f) { return f.get_symref(); });

  // this creates two virtual fields for each player that are
  // used to check if a player has a path across the board
  this->_create_player_src_dst_nodes();

  // welcome banner and symbol legend
  AsciiArt::banner(
    std::make_tuple(
      this->_players[0]->get_name(),
      this->_players[0]->get_symbol(),
      direction_string.at(this->_player_data[this->_players[0]->get_id()].second)),
    std::make_tuple(
      this->_players[1]->get_name(),
      this->_players[1]->get_symbol(),
      direction_string.at(this->_player_data[this->_players[1]->get_id()].second))
  );

  do {
    // swap players because it's the other one's turn
    player = this->_swap_player(player);

    HexBoard::print_board(board_symbols, this->_board_size);

    // ask player for the next move
    std::cout << player << "'s turn:" << std::endl;
    while (!this->_next_move(*player)) {
      std::cout << "illegal move, try again" << std::endl;
    }

  // keep playing until a winner is found
  } while (!this->_player_data[player->get_id()].first->fields_are_connected(
    player->get_src_dst_nodes()));

  // give the winner some nice banner
  AsciiArt::announce_winner(player->get_name());
  HexBoard::print_board(board_symbols, this->_board_size);
}


HexGame::~HexGame() {
  delete this->_player_data[this->_players[0]->get_id()].first;
  delete this->_player_data[this->_players[1]->get_id()].first;
  delete this->_players[0];
  delete this->_players[1];
}


// switch between the two players
Player* HexGame::_swap_player(Player* player) {
  return player == this->_players[0] ? this->_players[1] : this->_players[0];
}


bool HexGame::_next_move(Player& player) {
  std::list<int> adjacent_fields;
  int field;

  std::pair<int, int> move = player.get_move();

  // do some checks to verify if the move is valid
  if (!this->_verify_move(move, field))
    return false;

  // update the board field
  this->_fields[field].use_field(player.get_id(), player.get_symbol());

  // create the according edges in the graph
  HexBoard::get_adjacent_fields(field, this->_board_size, adjacent_fields);

  // copy indexes of fields that belong to player to adjacent_fields_of_player
  adjacent_fields.remove_if(
    [&](int i) { return this->_fields[i].get_owner() != player.get_id(); });

  // add edges to all fields that are adjacent and belong to player
  this->_player_data[player.get_id()].first->add_edges(field, adjacent_fields);

  // print the move to the console with some ascii art
  AsciiArt::print_players_move(player.get_name(), move);

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
  if ((field < 0) || (field >= this->_board_size * this->_board_size))
    return false;

  // check if field is still empty
  if (!this->_fields[field].is_empty())
    return false;

  // all checks ok
  return true; 
}


// creates 4 virtual nodes at the end of _board_size * _board_size to be used
// as virtual nodes that each player has to connect to win the game
void HexGame::_create_player_src_dst_nodes() {
  Player* player;

  // create 2 virtual nodes per player
  // append them at the end of the existing nodes
  for (int i = 0; i < 2; ++i)
    this->_players[i]->set_src_dst_nodes(std::pair<int, int>(
      this->_board_size * this->_board_size + 1 + i * 2,
      this->_board_size * this->_board_size + 2 + i * 2));

  for (auto player: this->_players) {
    std::pair< std::vector<int>, std::vector<int> > board_edge_nodes;

    // get the board edge fields for the current player's playing direction
    HexBoard::get_board_edge_fields(
        this->_board_size, this->_player_data[player->get_id()].second, board_edge_nodes);

    // connect all the board edge nodes to the current player's virtual node
    for (auto i: board_edge_nodes.first)
      this->_player_data[player->get_id()].first->add_edge(player->get_src_dst_nodes().first, i);
    for (auto i: board_edge_nodes.second)
      this->_player_data[player->get_id()].first->add_edge(player->get_src_dst_nodes().second, i);
  }
}
