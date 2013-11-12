#ifndef TYPES_H_
#define TYPES_H_

#include <utility>
#include <map>
#include <iostream>

typedef std::pair<int, int> move_t;

enum class board_direction {NORTH_SOUTH, WEST_EAST};

// map the directions to strings
const std::map<board_direction, std::string> direction_string {
  {board_direction::NORTH_SOUTH, std::string("North - South")},
  {board_direction::WEST_EAST, std::string("West - East")}
};

#endif  // TYPES_H_
