#ifndef PLAYER_H_
#define PLAYER_H_

#include <utility>
#include <iostream>


// this is the abstract base class for a player. it should be extended to be
// any type of player like human or computer or whatever else
class Player {
  protected:
    std::pair<int, int> _src_dst;
    std::string _player_name;
    char _symbol;
    int _id;

  public:
    Player();
    Player(const std::string, const char);
    Player(const char*, const char);
    virtual std::pair<int, int> get_move()=0;
    void set_name(std::string);
    std::string get_name();
    void set_symbol(const char);
    char get_symbol();
    void set_src_dst_nodes(std::pair<int, int>);
    std::pair<int, int> get_src_dst_nodes();
};

std::ostream& operator<< (std::ostream&, Player*);

#endif  // PLAYER_H_
