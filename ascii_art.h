#ifndef ASCII_ART_H_
#define ASCII_ART_H_

#include <iostream>
#include <iomanip>
#include <tuple>
#include <string>
#include <vector>
#include <limits>
#include <cmath>


// methods that print pretty ascii art like the hex board
class AsciiArt {
  private:
    static void _new_board_row(const int, int&);

  public:
    static void print_board(std::vector<char*>&, int);
    static void horizontal_line();
    static void horizontal_line(const char*);
    static void print_players_move(std::string, std::pair<int, int>);
    static void announce_winner(std::string);
    static int ask_user(std::string, std::vector<std::string>);
    static void three_columns(const char *,
                        std::string c1, std::string c2, std::string c3);
    static void banner(std::tuple<std::string, char, std::string>,
                       std::tuple<std::string, char, std::string>);
};

#endif  // ASCII_ART_
