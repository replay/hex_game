#ifndef BOARD_PRINTER_H_
#define BOARD_PRINTER_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <cmath>
#include <map>

// defines the direction in which a player has to create a path
enum class board_direction: short {WEST_EAST, NORTH_SOUTH};

// map the directions to strings
const std::map<board_direction, std::string> direction_string {
  {board_direction::WEST_EAST, std::string("West - East")},
  {board_direction::NORTH_SOUTH, std::string("North - South")}
};


// implements all logic that's necessary to calculate hexboard related data
class HexBoard {
  public:
    static void get_adjacent_fields(int, int, std::list<int>&);
    static void get_board_edge_fields(const int, board_direction,
      std::pair< std::vector<int>, std::vector<int> >&);
};

#endif  // BOARD_PRINTER_H_
