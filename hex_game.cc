#include "./hex_game.h"


HexGame::HexGame() {
  Player* player;
  std::vector<char*> board_symbols;

  // create the players
  this->_players.resize(2);
  this->_players[0] = new HumanPlayer(1, "player1", 'X');
  this->_players[1] = new HumanPlayer(2, "player2", 'O');

  // ask who gets the first move
  // the one who gets the first move will be the first element in the vector 
  if (AsciiArt::who_begins(this->_players[0], this->_players[1]) == 2) {
    player = this->_players[0];
    this->_players[0] = this->_players[1];
    this->_players[1] = player;
  }

  // current player is the first one
  player = this->_players[0];

  // set the playing direction for each of the two players
  this->_players[0]->set_board_direction(board_direction::WEST_EAST);
  this->_players[1]->set_board_direction(board_direction::NORTH_SOUTH);

  // let player choose the board size and initialize storage accordingly
  this->_board_size = AsciiArt::choose_board_size();
  this->_fields.resize(this->_board_size * this->_board_size);
  this->_edge_graph = new EdgeGraph(this->_board_size);
  board_symbols.resize(this->_board_size * this->_board_size);

  // create a list of pointers to the symbols of each field on the board
  std::transform (this->_fields.begin(), this->_fields.end(),
      board_symbols.begin(), [] (Field& f) { return f.get_symref(); });

  // this creates two virtual fields for each player that are
  // used to check if a player has a path across the board
  this->_create_player_src_dst_nodes();

  // welcome banner and symbol legend
  AsciiArt::banner(this->_players[0], this->_players[1]);

  // keep playing until there is a winner
  while (!this->_has_winner()) {
    HexBoard::print_board(board_symbols, this->_board_size);

    // ask player for the next move
    std::cout << player << "'s turn:" << std::endl;
    while (!this->_next_move(*player)) {
      std::cout << "illegal move, try again" << std::endl;
    }

    // switch the current player
    player = this->_swap_player(player);
  }
}


// switch between the two players
Player* HexGame::_swap_player(Player* player) {
  return player == this->_players[0] ? this->_players[1] : this->_players[0];
}


HexGame::~HexGame() {
  delete this->_players[0];
  delete this->_players[1];
  delete this->_edge_graph;
}


bool HexGame::_next_move(Player& player) {
  std::vector<int> adjacent_fields, adjacent_fields_of_player;
  int field;
  move_t move = player.get_move();

  // check if given values are in valid range
  if (move.first >= this->_board_size || move.second >= this->_board_size)
    return false;
  if (move.first < 0 || move.second < 0)
    return false;

  // convert two dimensional coordinates into field number
  field = move.second * this->_board_size + move.first;

  // more move validation
  if ((field < 0) || (field >= this->_board_size * this->_board_size))
    return false;

  // check if field is still empty
  if (!this->_fields[field].is_empty()) {
    return false;
  }

  // update the board field
  this->_fields[field].use_field(player.get_id(), player.get_symbol());

  // create the according edges in the graph
  HexBoard::get_adjacent_fields(field, this->_board_size, adjacent_fields);

  // max size of adjacent_fields_of_player is the size of adjacent_fields
  adjacent_fields_of_player.resize(adjacent_fields.size());

  // copy indexes of fields that belong to player to adjacent_fields_of_player
  std::copy_if(adjacent_fields.begin(), adjacent_fields.end(),
    adjacent_fields_of_player.begin(),
    [&](int i) { return this->_fields[i].get_owner() == player.get_id();}
  );

  // add edges to all fields that are adjacent and belong to player
  this->_edge_graph->add_edges(
    field, player.get_id(), adjacent_fields_of_player);

  // print the move to the console with some ascii art
  AsciiArt::print_players_move(&player, move);

  return true;
}


bool HexGame::_has_winner() {
  std::pair< std::vector<int>, std::vector<int> > board_edges;

  //HexBoard::get_board_edge_fields(this->_board_size, HexBoard::edge_direction::HORIZONTAL, board_edges);
  //HexBoard::get_board_edge_fields(this->_board_size, HexBoard::edge_direction::VERTICAL, board_edges);

  return false;
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
        this->_board_size, player->get_board_direction(), board_edge_nodes);

    // connect all the board edge nodes to the current player's virtual node
    for (auto i: board_edge_nodes.first)
      this->_edge_graph->add_edge(player->get_id(), player->get_src_dst_nodes().first, i);
    for (auto i: board_edge_nodes.second)
      this->_edge_graph->add_edge(player->get_id(), player->get_src_dst_nodes().second, i);
  }
}
