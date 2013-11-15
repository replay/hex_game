#ifndef HUMAN_PLAYER_H_
#define HUMAN_PLAYER_H_

#include <iostream>
#include <limits>
#include "./player.h"


// extends the Player object to represent a human player
class HumanPlayer: public Player {
  private:
    bool _is_numeric(std::string&);
    inline int _get_coordinate(char);

  public:
    HumanPlayer();
    HumanPlayer(const std::string, const char);
    HumanPlayer(const char*, const char);
    std::pair<int, int> get_move();
};

#endif  // HUMAN_PLAYER_H_
