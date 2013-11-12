#ifndef TYPES_H_
#define TYPES_H_

#include <utility>
#include <map>
#include <iostream>

typedef std::pair<int, int> move_t;

enum class board_direction: short {WEST_EAST, NORTH_SOUTH};

// map the directions to strings
const std::map<board_direction, std::string> direction_string {
  {board_direction::WEST_EAST, std::string("West - East")},
  {board_direction::NORTH_SOUTH, std::string("North - South")}
};

#endif  // TYPES_H_
