#ifndef PLAYER_CONTAINER_H_
#define PLAYER_CONTAINER_H_

#include <vector>
#include <utility>

#include "./player.h"
#include "./types.h"

class PlayerContainer {
  private:
    std::vector<Player*> _players;
    int _currently_active = 0;
    int _virtual_start;
  public:
    ~PlayerContainer();
    bool add_player(Player*);
    void swap_active();
    void swap_player_position();
    char get_symbol(int);
    char get_symbol();
    std::pair<int, int> get_src_dst_nodes(int);
    std::vector<Player*>::iterator begin();
    std::vector<Player*>::iterator end();
    std::pair<int, int> get_move();
    int get_active_id();
    std::string get_name(int);
    std::string get_name();
    void set_virtual_start(int);
};

#endif  // PLAYER_CONTAINER_H_
