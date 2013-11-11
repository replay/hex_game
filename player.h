#ifndef PLAYER_H_
#define PLAYER_H_

#include "./types.h"
#include "./field.h"
#include "./game_status.h"

class Player {
  private:
    Field::colors _color;
    GameStatus& _game_status;

  protected:
    std::string _player_name;

  public:
    Player(GameStatus&);
    Player(GameStatus&, const std::string);
    Player(GameStatus&, const char*);
    virtual move_t get_move()=0;
    void set_color(Field::colors);
    Field::colors get_color();
    void set_player_name(std::string);
    std::string get_player_name();
};

std::ostream& operator<< (std::ostream&, Player*);

#endif  // PLAYER_H_
