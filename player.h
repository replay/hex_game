#ifndef PLAYER_H_
#define PLAYER_H_

#include "./types.h"
#include "./field.h"

class Player {
  private:
    Field::colors _color;

  protected:
    std::string _player_name;

  public:
    Player();
    Player(const std::string);
    Player(const char*);
    virtual move_t get_move()=0;
    void set_color(Field::colors);
    Field::colors get_color();
    void set_player_name(std::string);
    std::string get_player_name();
};

std::ostream& operator<< (std::ostream&, Player*);

#endif  // PLAYER_H_
