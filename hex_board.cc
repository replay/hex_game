#include "./hex_board.h"

void HexBoard::print(std::vector<Field>& fields, int board_size) {
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

