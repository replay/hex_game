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
    _player1 = new HumanPlayer(_game_status, "the whit0r");
    _player1->set_color(Field::colors::BLACK);
    _player2 = new HumanPlayer(_game_status, "another one");
    _player2->set_color(Field::colors::WHITE);
   
    game();
}

Hex::~Hex() {
  delete _player1;
  delete _player2;
}

void Hex::game() {
  Player* player;
  for (int i = 0; !_game_status.is_finished(); ++i) {
    _board_printer.print(_game_status);

    if (i % 2 == 0) {
      player = _player1;
    } else {
      player = _player2;
    }
    std::cout << player << "'s turn" << std::endl;
    move(*player);
  }
}

void Hex::move(Player& player) {
  int fieldnum = _move_to_fieldnum(player.get_move());
  while (!_game_status.set_field(fieldnum, player.get_color())) {
    std::cout << "illegal move, try again" << std::endl;
    fieldnum = _move_to_fieldnum(player.get_move());
  }
}

int Hex::_move_to_fieldnum(move_t m) {
  return m.second * _board_size + m.first;
}
