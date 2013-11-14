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

int AsciiArt::ask_user(std::string question, std::vector<std::string> choices) {
  int choice = 0;

  AsciiArt::horizontal_line();

  std::cout << question << std::endl;

  while (choice < 1 || choice > choices.size()) {
    for (int i = 0; i < choices.size(); ++i) {
      std::cout << i + 1 << ") : " << choices[i] << std::endl;
    }
    std::cin >> choice;
  }
  return choice - 1;
}

void AsciiArt::banner(std::tuple<std::string, char, std::string> p1,
                      std::tuple<std::string, char, std::string> p2) {
  AsciiArt::horizontal_line("*");
  std::cout << "*" << std::setw(77) << "HEX GAME LEGEND" << " *" << std::endl;
  AsciiArt::horizontal_line("*");
  AsciiArt::three_columns("*",
    std::string("ITEM"),
    std::string("SYMBOL"),
    std::string("DIRECTION"));
  AsciiArt::horizontal_line("*");
  AsciiArt::three_columns("*",
    std::string("empty field"),
    std::string("."),
    std::string(""));
  AsciiArt::three_columns("*",
    std::get<0>(p1),
    std::string(1, std::get<1>(p1)),
    std::get<2>(p1));
  AsciiArt::three_columns("*",
    std::get<0>(p2),
    std::string(1, std::get<1>(p2)),
    std::get<2>(p2));
  AsciiArt::horizontal_line("*");
}

void AsciiArt::print_players_move(std::string player, std::pair<int, int> move) {
  std::cout << std::endl;
  AsciiArt::horizontal_line();
  std::cout << "\"" << player << "\" played " <<
    move.first + 1 << ":" << move.second + 1 << std::endl;
  AsciiArt::horizontal_line();
}

void AsciiArt::announce_winner(std::string winner) {
  int msg_len = 78 - 15 - winner.size();

  AsciiArt::horizontal_line("+");
  std::cout << "+";
  for (int i = 0; i < 78; ++i)
    std::cout << " ";
  std::cout << "+" << std::endl;
  std::cout << "+";
  for (int i = 0; i < msg_len / 2; ++i)
    std::cout << " ";
  std::cout << "the winner is: " << winner;
  if (msg_len % 2 == 1)
    std::cout << " ";
  for (int i = 0; i < msg_len / 2; ++i)
    std::cout << " ";
  std::cout << "+" << std::endl;
  std::cout << "+";
  for (int i = 0; i < 78; ++i)
    std::cout << " ";
  std::cout << "+" << std::endl;
  AsciiArt::horizontal_line("+");
}
