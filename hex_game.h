#ifndef HEX_H_
#define HEX_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <tuple>

#include <cmath>

#include "./types.h"
#include "./field.h"
#include "./ascii_art.h"
#include "./hex_board.h"
#include "./edge_graph.h"
#include "./player_container.h"
#include "./human_player.h"

/*const std::map< int, board_direction > player_directions = {
  std::pair< int, board_direction >(0, board_direction::WEST_EAST,
  std::pair< int, board_direction >(1, board_direction::NORTH_SOUTH
};*/

const std::map<int, board_direction> player_directions = {
  {0, board_direction::WEST_EAST},
  {1, board_direction::NORTH_SOUTH}
};

class HexGame {
  private:
    PlayerContainer _players;
    std::vector<EdgeGraph*> _edge_graphs;
    std::vector<Field> _fields;

    int _board_size = 0;
    std::vector<int> _board_choices = {4, 7, 11, 13, 17};

    bool _verify_move(std::pair<int, int>&, int&);
    bool _next_move();
    void _create_player_src_dst_nodes();
    //Player* _swap_player(Player*);

  public:
    HexGame();
    ~HexGame();
};

#endif  // HEX_H_
