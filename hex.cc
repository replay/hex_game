#include "./hex.h"
#include "./board_printer.h"
#include "./human_player.h"

Hex::Hex(int board_size)
  : _board_size(board_size),
  _board_printer(BoardPrinter()),
  _game_status(GameStatus(board_size)) {
    if (board_size > 99) {
      std::cerr << "board size can't be bigger than 99x99" << std::endl;
      return;
    }

    // create the players
    this->_player1 = new HumanPlayer(_game_status, "the whit0r");
    this->_player1->set_color(Field::colors::BLACK);
    this->_player2 = new HumanPlayer(_game_status, "another one");
    this->_player2->set_color(Field::colors::WHITE);

    this->_game();
}

Hex::~Hex() {
  delete this->_player1;
  delete this->_player2;
}

void Hex::_game() {
  Player* player;
  for (int i = 0; !this->_game_status.is_finished(); ++i) {
    this->_board_printer.print(this->_game_status);

    if (i % 2 == 0) {
      player = this->_player1;
    } else {
      player = this->_player2;
    }

    std::cout << player << "'s turn" << std::endl;
    this->_move(*player);
    _game_status.has_winner();
  }
}

void Hex::_move(Player& player) {
  int fieldnum = this->_move_to_fieldnum(player.get_move());
  while (!this->_game_status.set_field(fieldnum, player.get_color())) {
    std::cout << "illegal move, try again" << std::endl;
    fieldnum = this->_move_to_fieldnum(player.get_move());
  }
}

int Hex::_move_to_fieldnum(move_t m) {
  if (m.first >= this->_board_size || m.second >= this->_board_size)
    return -1;
  if (m.first < 0 || m.second < 0)
    return -1;
  return m.second * this->_board_size + m.first;
}
