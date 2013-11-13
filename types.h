#ifndef TYPES_H_
#define TYPES_H_

#include <utility>
#include <map>
#include <iostream>
#include <vector>

// coordinates of a move that's give by a player
typedef std::pair<int, int> move_t;

// an edge in the graph
typedef std::map< int, std::vector< int > > edge_t;

// map of edges, first int is to select the player
typedef std::map< int, edge_t > edge_list_t;

// defines the direction in which a player has to create a path
enum class board_direction: short {WEST_EAST, NORTH_SOUTH};

// map the directions to strings
const std::map<board_direction, std::string> direction_string {
  {board_direction::WEST_EAST, std::string("West - East")},
  {board_direction::NORTH_SOUTH, std::string("North - South")}
};

#endif  // TYPES_H_
