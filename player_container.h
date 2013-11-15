#ifndef PLAYER_CONTAINER_H_
#define PLAYER_CONTAINER_H_

#include <vector>
#include <utility>
#include <iostream>

#include "./player.h"
#include "./human_player.h"

// defines the possible player types
enum class player_type: short {HUMAN};

class PlayerContainer {
  private:
    std::vector<Player*> _players;
    char _get_free_symbol();
    int _currently_active = 0;
    int _virtual_start;
  public:
    ~PlayerContainer();
    void swap_active();
    void swap_player_position();
    void set_virtual_start(int);

    bool add_player(Player*);
    int create_player(const char*, const player_type);

    char get_symbol(int);
    char get_symbol();
    int get_active_id();

    std::pair<int, int> get_src_dst_nodes(int);
    std::pair<int, int> get_src_dst_nodes();

    std::pair<int, int> get_move(int);
    std::pair<int, int> get_move();

    std::string get_name(int);
    std::string get_name();

    std::vector<Player*>::iterator begin();
    std::vector<Player*>::iterator end();
};

#endif  // PLAYER_CONTAINER_H_
