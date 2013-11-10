#include <iostream>
#include "./board_printer.h"

void BoardPrinter::print(GameStatus& s) {
  int board_size = s.board_size();
  int indentations = 0;

  for (auto i = s.field_ref().begin(); i < s.field_ref().end(); ++i) {
    if ((i - s.field_ref().begin()) % board_size != 0)
      std::cout << " - ";

    std::cout << *i;

    if ((i - s.field_ref().begin()) % board_size == board_size - 1 &&
        (i - s.field_ref().begin()) != board_size * board_size - 1) {
      _newline(board_size, indentations);
    }
  }

  std::cout << std::endl;
}

void BoardPrinter::_newline(const int board_size, int& indentations) {
  std::cout << std::endl;

  for (int i = 0; i < indentations * 2; ++i)
    std::cout << " ";
  std::cout << " ";

  for (int i = 0; i < board_size - 1; ++i)
    std::cout << "\\ / ";
  std::cout << " \\" << std::endl;

  ++indentations;

  for (int i = 0; i < indentations * 2; ++i)
    std::cout << " ";
}

