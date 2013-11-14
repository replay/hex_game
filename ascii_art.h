#ifndef ASCII_ART_H_
#define ASCII_ART_H_

#include <iostream>
#include <iomanip>
#include "./player.h"

class AsciiArt {
  public:
    static void horizontal_line();
    static void horizontal_line(const char*);
    static void three_columns(const char *,
      std::string c1, std::string c2, std::string c3);
    static void banner(Player*, Player*);
    static int who_begins(Player*, Player*);
    static int choose_board_size();
    static void print_players_move(Player*, std::pair<int, int>);
    static void announce_winner(std::string);
};

#endif  // ASCII_ART_
