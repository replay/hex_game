#ifndef HEX_H_
#define HEX_H_

#include "./game_status.h"
#include "./board_printer.h"

class Hex {
  private:
    GameStatus _game_status;
    BoardPrinter _board_printer;
    int _board_size;


  public:
    Hex(int = 11);
};

#endif  // HEX_H_
