#ifndef PLAYER_H_
#define PLAYER_H_

#include "./types.h"
#include "./field.h"
#include "./game_status.h"

class Player {
  private:
    Field::colors _color;
    GameStatus& _game_status;

  public:
    Player(GameStatus& _game_status);
    virtual move_t get_move()=0;
    void set_color(Field::colors);
    Field::colors get_color();
};

#endif  // PLAYER_H_
