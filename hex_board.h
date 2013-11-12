#ifndef BOARD_PRINTER_H_
#define BOARD_PRINTER_H_

#include <iostream>
#include <iomanip>
#include <vector>

#include "./field.h"

class HexBoard {
  private:
    static void _newline(const int, int&);

  public:
    enum class edge_direction {HORIZONTAL, VERTICAL};
    static void print_board(std::vector<Field>&, int);
    static void get_adjacent_fields(int, int, std::vector<int>&);
    static void get_board_edge_fields(const int, edge_direction,
      std::pair< std::vector<int>, std::vector<int> >&);
};

#endif  // BOARD_PRINTER_H_
