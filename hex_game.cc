#include "./hex_game.h"

HexGame::HexGame(int board_size)
  : _board_size(board_size),
  _edge_graph(EdgeGraph(board_size, this->_fields)) {

  if (board_size > 99) {
    std::cerr << "board size can't be bigger than 99x99" << std::endl;
    return;
  }

  // create the players
  this->_player1 = new HumanPlayer("the whit0r");
  this->_player1->set_color(Field::colors::BLACK);
  this->_player2 = new HumanPlayer("another one");
  this->_player2->set_color(Field::colors::WHITE);

  // start with player1
  Player* player = this->_player1;

  this->_fields.resize(this->_board_size * this->_board_size);

  // keep playing until there is a winner
  while (!this->_has_winner()) {
    HexBoard::print_board(this->_fields, this->_board_size);

    if (player == this->_player1) {
      player = this->_player2;
    } else {
      player = this->_player1;
    }

    std::cout << player << "'s turn" << std::endl;
    while (!this->_next_move(*player)) {
      std::cout << "illegal move, try again" << std::endl;
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

  // further move validation
  if (field < 0)
    return false;
  if (field >= this->_board_size * this->_board_size)
    return false;

  // check if field is still empty
  if (this->_fields[field].get_color() != Field::colors::EMPTY)
    return false;

  this->_fields[field].set_color(player.get_color());
  this->_edge_graph.update_edges(field, player.get_color());

  return true;
}

bool HexGame::_has_winner() {

  /*for (int i = 0; i < this->_board_size; ++i) {
    for (int j = 0; j < this->_board_size; ++j) {
      if (this->_edge_graph.find_path(i,
        (this->_board_size - 1) * this->_board_size + j, Field::colors::BLACK)) {
        this->_winner = Field::colors::BLACK;
        return true;
      }
    }
  }

  for (int i = 0; i < this->_board_size; ++i) {
    for (int j = 0; j < this->_board_size; ++j) {
      if (this->_edge_graph.find_path(
        i * this->_board_size, j * this->_board_size + this->_board_size - 1,
        Field::colors::BLACK)) {
        this->_winner = Field::colors::BLACK;
        return true;
      }
    }
  }*/

  return false;
}
