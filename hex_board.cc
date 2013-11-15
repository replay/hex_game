#include "./hex_board.h"


// creates a list of all fields on either the two vertical or the two
// horizontal edges of the hex board.
void HexBoard::get_board_edge_fields(const int board_size, board_direction dir,
  std::pair< std::vector<int>, std::vector<int> >& edges) {

  // initialize for NORTH_SOUTH
  int incr = 1;
  int dst_start = board_size * (board_size - 1);

  // if HORIZONTAL, then overwrite values
  if (dir == board_direction::WEST_EAST) {
    dst_start = board_size - 1;
    incr = board_size;
  }

  // generate the fields of first edge (either left or top)
  for (int i = 0; i < incr * board_size; i += incr)
    edges.first.push_back(i);

  // generate the fields of second edge (either right or bottom)
  for (int i = dst_start; i < dst_start + (board_size * incr); i += incr)
    edges.second.push_back(i);
}


// creates a list of all fields that are adjacent to a given field based
// on the size of the hex board. takes into account that fields at the edge
// of the board do not have all 6 adjacent fields.
void HexBoard::get_adjacent_fields(
  int field, int board_size, std::list<int>& adjacent_fields) {
  std::vector< std::pair<int, bool> > surrounding_hexagon;

  // adding all possible neighbours to surrounding_hexagon
  surrounding_hexagon.push_back(std::pair<int, bool>(field - board_size, true));
  surrounding_hexagon.push_back(std::pair<int, bool>(field - board_size + 1, true));
  surrounding_hexagon.push_back(std::pair<int, bool>(field + 1, true));
  surrounding_hexagon.push_back(std::pair<int, bool>(field + board_size, true));
  surrounding_hexagon.push_back(std::pair<int, bool>(field + board_size - 1, true));
  surrounding_hexagon.push_back(std::pair<int, bool>(field - 1, true));

  // field is on the left edge
  if (field % board_size == 0) {
    surrounding_hexagon[4].second = false;
    surrounding_hexagon[5].second = false;
  }
  // field is on the right edge
  if ((field + 1) % board_size == 0) {
    surrounding_hexagon[1].second = false;
    surrounding_hexagon[2].second = false;
  }
  // field is on the top edge
  if (field < board_size) {
    surrounding_hexagon[0].second = false;
    surrounding_hexagon[1].second = false;
  }
  // field is on the bottom edge
  if (field >= board_size * (board_size - 1)) {
    surrounding_hexagon[3].second = false;
    surrounding_hexagon[4].second = false;
  }

  // all edges that aren't sent to false do exist on the board
  for (auto i: surrounding_hexagon)
    if (i.second)
      adjacent_fields.push_back(i.first);
}
