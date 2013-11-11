#ifndef HEX_H_
#define HEX_H_

#include <iostream>

#include "./game_status.h"
#include "./board_printer.h"
#include "./player.h"

typedef class illegal_move_exception: public std::exception {
} illegal_move_exception;

class Hex {
  private:
    GameStatus _game_status;
    BoardPrinter _board_printer;
    Player* _player1;
    Player* _player2;
    int _board_size;
    int _move_to_fieldnum(move_t);
    void _move(Player&);
    bool _is_finished();
    void _game();

  public:
    Hex(int = 11);
    ~Hex();
};

#endif  // HEX_H_
