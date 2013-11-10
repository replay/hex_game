#include "./hex.h"
#include "./board_printer.h"

Hex::Hex(int board_size)
 : _board_size(board_size),
   _board_printer(BoardPrinter()),
   _game_status(GameStatus(board_size)) {
   _board_printer.print(_game_status);
}
