#include "./hex_game.h"

HexGame::HexGame() {
  Player* player;

  // create the players
  this->_player1 = new HumanPlayer("player1", 'X');
  this->_player2 = new HumanPlayer("player2", 'O');
  if (AsciiArt::who_begins(this->_player1, this->_player2) == 1)
    player = this->_player1;
  else
    player = this->_player2;

  this->_board_size = AsciiArt::choose_board_size();

  this->_fields.resize(this->_board_size * this->_board_size);

  this->_edge_graph = new EdgeGraph(this->_board_size, this->_fields);

  AsciiArt::banner(this->_player1, this->_player2);

  // keep playing until there is a winner
  while (!this->_has_winner()) {
    HexBoard::print_board(this->_fields, this->_board_size);

    std::cout << player << "'s turn:" << std::endl;
    while (!this->_next_move(*player)) {
      std::cout << "illegal move, try again" << std::endl;
    }

    if (player == this->_player1) {
      player = this->_player2;
    } else {
      player = this->_player1;
    }
  }
}

HexGame::~HexGame() {
  delete this->_player1;
  delete this->_player2;
}

bool HexGame::_next_move(Player& player) {
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
  if (field < 0)
    return false;
  if (field >= this->_board_size * this->_board_size)
    return false;

  // check if field is still empty
  if (!this->_fields[field].is_empty()) {
    return false;
  }

  this->_fields[field].set_symbol(player.get_symbol());
  this->_edge_graph->update_edges(field, &player);

  AsciiArt::print_players_move(&player, move);

  return true;
}

bool HexGame::_has_winner() {

  std::pair< std::vector<int>, std::vector<int> > board_edges;

  //HexBoard::get_board_edge_fields(this->_board_size, HexBoard::edge_direction::HORIZONTAL, board_edges);
  //HexBoard::get_board_edge_fields(this->_board_size, HexBoard::edge_direction::VERTICAL, board_edges);

  return false;
}
