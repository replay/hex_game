#ifndef TYPES_H_
#define TYPES_H_

#include <utility>
#include <map>
#include <iostream>
#include <vector>

// defines the direction in which a player has to create a path
enum class board_direction: short {WEST_EAST, NORTH_SOUTH};

// map the directions to strings
const std::map<board_direction, std::string> direction_string {
  {board_direction::WEST_EAST, std::string("West - East")},
  {board_direction::NORTH_SOUTH, std::string("North - South")}
};

#endif  // TYPES_H_
