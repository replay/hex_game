#ifndef HUMAN_PLAYER_H_
#define HUMAN_PLAYER_H_

#include <iostream>
#include "./player.h"

class HumanPlayer: public Player {
  private:
    bool _is_numeric(std::string&);

  public:
    HumanPlayer();
    HumanPlayer(const std::string);
    HumanPlayer(const char*);
    HumanPlayer(const std::string, const char);
    HumanPlayer(const char*, const char);
    move_t get_move();
};

#endif  // HUMAN_PLAYER_H_
