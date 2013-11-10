#ifndef HEX_H_
#define HEX_H_

#include <iostream>

#include "./game_status.h"
#include "./board_printer.h"
#include "./player.h"

class Hex {
  private:
    GameStatus _game_status;
    BoardPrinter _board_printer;
    Player * _player1;
    Player * _player2;
    int _board_size;

  public:
    Hex(int = 11);
    ~Hex();
    void game();
    bool is_finished();
    void move(Player&);
};

#endif  // HEX_H_
