#include "./hex.h"
#include "./board_printer.h"
#include "./human_player.h"

Hex::Hex(int board_size)
 : _board_size(board_size),
   _board_printer(BoardPrinter()),
   _game_status(GameStatus(board_size)) {
   game();

   _player1 = new HumanPlayer(_game_status);
   _player1->set_color(Field::colors::BLACK);

   _player2 = new HumanPlayer(_game_status);
   _player2->set_color(Field::colors::WHITE);
}

Hex::~Hex() {
  delete _player1;
  delete _player2;
}

void Hex::game() {
  for (int i = 0; !_game_status.is_finished(); ++i) {
    _board_printer.print(_game_status);

    if (i % 2 == 0) {
      move(*_player1);
    } else {
      move(*_player2);
    }
  }
}

void Hex::move(Player& player) {
  move_t move = player.get_move();
  int fieldnum = move.first * _board_size + move.second;
  _game_status.set_field(fieldnum, player.get_color());
}
