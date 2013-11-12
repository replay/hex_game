#ifndef BOARD_PRINTER_H_
#define BOARD_PRINTER_H_

#include <iostream>
#include <iomanip>
#include <vector>

#include "./types.h"

class HexBoard {
  private:
    static void _newline(const int, int&);

  public:
    static void print_board(std::vector<char*>&, int);
    static void get_adjacent_fields(int, int, std::vector<int>&);
    static void get_board_edge_fields(const int, board_direction,
      std::pair< std::vector<int>, std::vector<int> >&);
};

#endif  // BOARD_PRINTER_H_
