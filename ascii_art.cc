#include "./ascii_art.h"


// print horizontal row on the ascii-art board
void AsciiArt::_new_board_row(const int board_size, int& indentations) {
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


// print the hex board in ascii art
void AsciiArt::print_board(std::vector<char*>& fields, int board_size) {
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
        (i - fields.begin()) != pow(board_size, 2) - 1) {
      AsciiArt::_new_board_row(board_size, indentations);
    }
  }

  std::cout << std::endl;
  for (int i = 0; i < indentations * 2; ++i)
    std::cout << " ";
  std::cout << "  (y)";

  std::cout << std::endl;
}


// line of 80 '-' characters and newline
void AsciiArt::horizontal_line() {
  AsciiArt::horizontal_line("-");
}


// print 80 times a given character and newline
void AsciiArt::horizontal_line(const char* c) {
  for (int i = 0; i < 80; ++i)
    std::cout << c;
  std::cout << std::endl;
}


// output the move that has been given by a player
void AsciiArt::print_players_move(std::string player, std::pair<int, int> move) {
  std::cout << std::endl;
  AsciiArt::horizontal_line();
  std::cout << "\"" << player << "\" played " <<
    move.first + 1 << ":" << move.second + 1 << std::endl;
  AsciiArt::horizontal_line();
}


// print a nice banner for the winner of the game
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


// asks the user a given question with multiple choices. reads user input
int AsciiArt::ask_user(
  std::string question, std::vector<std::string> choices) {

  int choice = 0;

  AsciiArt::horizontal_line();

  std::cout << question << std::endl;

  while (choice < 1 || choice > choices.size()) {
    for (int i = 0; i < choices.size(); ++i) {
      std::cout << i + 1 << ") : " << choices[i] << std::endl;
    }
    std::cout << "your choice: ";
    std::cin >> choice;

    // handle strange inputs like Ctrl+D (EOF)
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return choice - 1;
}


// print three columns with given values. used to print a table
void AsciiArt::three_columns(const char* separator,
  std::string c1, std::string c2, std::string c3) {

  // total width is 80
  std::cout << separator;
  std::cout << std::setw(24) << c1 << " " << separator;
  std::cout << std::setw(25) << c2 << " " << separator;
  std::cout << std::setw(24) << c3 << " " << separator;
  std::cout << std::endl;
}


// print the welcome banner when the game starts
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
