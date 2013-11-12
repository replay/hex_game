#include "./hex_game.h"

HexGame::HexGame(int board_size)
  : _board_size(board_size),
  _edge_graph(EdgeGraph(board_size, this->_fields)) {
  if (board_size > 99) {
    std::cerr << "board size can't be bigger than 99x99" << std::endl;
    return;
  }

  Player* player;

  this->_fields.resize(this->_board_size * this->_board_size);

  // create the players
  this->_player1 = new HumanPlayer("the whit0r");
  this->_player1->set_color(Field::colors::BLACK);
  this->_player2 = new HumanPlayer("another one");
  this->_player2->set_color(Field::colors::WHITE);

  for (int i = 0; !this->_is_finished(); ++i) {
    HexBoard::print_board(this->_fields, this->_board_size);

    if (i % 2 == 0) {
      player = this->_player1;
    } else {
      player = this->_player2;
    }

    std::cout << player << "'s turn" << std::endl;
    this->_move(*player);
    this->_has_winner();
  }
}

HexGame::~HexGame() {
  delete this->_player1;
  delete this->_player2;
}

void HexGame::_move(Player& player) {
  int fieldnum = this->_move_to_fieldnum(player.get_move());
  while (!this->_set_field(fieldnum, player.get_color())) {
    std::cout << "illegal move, try again" << std::endl;
    fieldnum = this->_move_to_fieldnum(player.get_move());
  }
}

int HexGame::_move_to_fieldnum(move_t m) {
  if (m.first >= this->_board_size || m.second >= this->_board_size)
    return -1;
  if (m.first < 0 || m.second < 0)
    return -1;
  return m.second * this->_board_size + m.first;
}

void HexGame::_build_paths() {
}

bool HexGame::_set_field(int field, Field::colors color) {
  if (field < 0)
    return false;
  if (field >= this->_fields.size())
    return false;
  if (this->_fields[field].get_color() != Field::colors::EMPTY)
    return false;

  this->_fields[field].set_color(color);
  this->_edge_graph.update_edges(field, color);
  return true;
}

Field::colors HexGame::_get_winner() {
  return this->_winner;
}

bool HexGame::_has_winner() {
  this->_build_paths();

  for (int i = 0; i < this->_board_size; ++i) {
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
  }

  return false;
}

bool HexGame::_is_finished() {
  return this->_finished;
}
