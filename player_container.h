#ifndef PLAYER_CONTAINER_H_
#define PLAYER_CONTAINER_H_

#include <vector>
#include <utility>
#include <iostream>
#include <numeric>

#include "./player.h"
#include "./human_player.h"

// defines the possible player types
enum class player_type: short {HUMAN};


// a container to hold and use the player objects
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

    std::vector<std::string> get_all_player_names();
};

#endif  // PLAYER_CONTAINER_H_
