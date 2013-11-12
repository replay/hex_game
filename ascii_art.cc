#include "./ascii_art.h"

void AsciiArt::horizontal_line() {
  AsciiArt::horizontal_line("-");
}

void AsciiArt::horizontal_line(const char* c) {
  for (int i = 0; i < 80; ++i)
    std::cout << c;
  std::cout << std::endl;
}

void AsciiArt::three_columns(const char* separator,
  std::string c1, std::string c2, std::string c3) {

  // total width is 80
  std::cout << separator;
  std::cout << std::setw(24) << c1 << " " << separator;
  std::cout << std::setw(25) << c2 << " " << separator;
  std::cout << std::setw(24) << c3 << " " << separator;
  std::cout << std::endl;
}

int AsciiArt::who_begins(Player* p1, Player* p2) {
  int choice = 0;

  AsciiArt::horizontal_line();

  std::cout << "which player gets the first move?" << std::endl;
  while (choice != 1 && choice != 2) {
    std::cout << "1) " << p1 << std::endl;
    std::cout << "2) " << p2 << std::endl;
    std::cout << "your choice: ";
    std::cin >> choice;
  }
  return choice;
}

int AsciiArt::choose_board_size() {
  int choice = 0;

  AsciiArt::horizontal_line();

  std::cout << "choose your board size" << std::endl;
  while (choice <= 0 || choice > 4) {
    std::cout << "1) : 7x7" << std::endl;
    std::cout << "2) : 11x11" << std::endl;
    std::cout << "3) : 13x13" << std::endl;
    std::cout << "4) : 17x17" << std::endl;
    std::cin >> choice;
  }
  switch (choice) {
    case 1:
      return 7;
    case 2:
      return 11;
    case 3:
      return 13;
    case 4:
      return 17;
  }
}

void AsciiArt::banner(Player* p1, Player* p2) {
  AsciiArt::horizontal_line("*");
  std::cout << "*" << std::setw(77) << "HEX GAME LEGEND" << " *" << std::endl;
  AsciiArt::horizontal_line("*");
  AsciiArt::three_columns("*",
    std::string("ITEM"),
    std::string("SYMBOL"),
    std::string("NOTES"));
  AsciiArt::horizontal_line("*");
  AsciiArt::three_columns("*",
    std::string("EMPTY FIELD"),
    std::string("."),
    std::string(""));
  AsciiArt::three_columns("*",
    p1->get_name(),
    std::string(1, p1->get_symbol()),
    std::string("connects West <-> East"));
  AsciiArt::three_columns("*",
    p2->get_name(),
    std::string(1, p2->get_symbol()),
    std::string("connects North <-> South"));
  AsciiArt::horizontal_line("*");
}

void AsciiArt::print_players_move(Player* player, move_t move) {
  std::cout << std::endl;
  AsciiArt::horizontal_line();
  std::cout << "\"" << player << "\" played " <<
    move.first << ":" << move.second << std::endl;
  AsciiArt::horizontal_line();
}
