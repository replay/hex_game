#ifndef HUMAN_PLAYER_H_
#define HUMAN_PLAYER_H_

#include "./player.h"

class HumanPlayer: public Player {
  private:

  public:
    HumanPlayer(GameStatus&);
    move_t get_move();
};

#endif  // HUMAN_PLAYER_H_
