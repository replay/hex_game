#ifndef HUMAN_PLAYER_H_
#define HUMAN_PLAYER_H_

#include <iostream>
#include "./player.h"


// this class represents a user player on the console
class HumanPlayer: public Player {
  private:
    bool _is_numeric(std::string&);

  public:
    HumanPlayer();
    HumanPlayer(int, const std::string, const char);
    HumanPlayer(int, const char*, const char);
    std::pair<int, int> get_move();
};

#endif  // HUMAN_PLAYER_H_
