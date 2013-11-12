#include "./hex_board.h"

void HexBoard::print_board(std::vector<Field>& fields, int board_size) {
  int indentations = 0;

  std::cout << " ";
  for (int i = 0; i < board_size; ++i) {
    std::cout << std::setw(4) << i + 1;
  }
  std::cout << std::setw(4) << "(x)";
  std::cout << std::endl;

  for (auto i = fields.begin(); i < fields.end(); ++i) {
    if ((i - fields.begin()) % board_size != 0) {
      std::cout << " - ";
    } else {
      std::cout << std::setw(3) << (i - fields.begin()) / board_size + 1 << " ";
    }

    std::cout << *i;

    if ((i - fields.begin()) % board_size == board_size - 1 &&
        (i - fields.begin()) != board_size * board_size - 1) {
      HexBoard::_newline(board_size, indentations);
    }
  }

  std::cout << std::endl;
  for (int i = 0; i < indentations * 2; ++i)
    std::cout << " ";
  std::cout << "  (y)";

  std::cout << std::endl;
}

// creates a list of all fields that are adjacent to a given field based
// on the size of the hex board
void HexBoard::get_adjacent_fields(
  int field, int board_size, std::vector<int>& adjacent_fields) {
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

  for (auto i: surrounding_hexagon)
    if (i.second)
      adjacent_fields.push_back(i.first);
}

void HexBoard::_newline(const int board_size, int& indentations) {
  std::cout << std::endl;

  for (int i = 0; i < indentations * 2; ++i)
    std::cout << " ";
  std::cout << "     ";


  for (int i = 0; i < board_size - 1; ++i)
    std::cout << "\\ / ";
  std::cout << "\\" << std::endl;

  ++indentations;

  for (int i = 0; i < indentations * 2; ++i)
    std::cout << " ";
}
