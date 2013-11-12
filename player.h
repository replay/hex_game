#ifndef PLAYER_H_
#define PLAYER_H_

#include "./types.h"
#include "./field.h"

// this is the abstract base class for a player
// it should be extended to be a human or a computer player
class Player {
  protected:
    std::string _player_name;
    char _symbol;

  public:
    Player();
    Player(const std::string);
    Player(const char*);
    Player(const std::string, const char);
    Player(const char*, const char);
    virtual move_t get_move()=0;
    void set_name(std::string);
    std::string get_name();
    void set_symbol(const char);
    char get_symbol();
};

std::ostream& operator<< (std::ostream&, Player*);

#endif  // PLAYER_H_
