#ifndef BOARD_PRINTER_H_
#define BOARD_PRINTER_H_

#include "./game_status.h"
#include "./field.h"

class BoardPrinter {
  private:
    void _newline(const int, int&);

  public:
    void print(GameStatus&);
};

#endif  // BOARD_PRINTER_H_
