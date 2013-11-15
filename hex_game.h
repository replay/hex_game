#ifndef HEX_H_
#define HEX_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#include <cmath>

#include "./field.h"
#include "./ascii_art.h"
#include "./hex_board.h"
#include "./edge_graph.h"
#include "./player_container.h"

// implements the logic of the hex game
class HexGame {
  private:
    PlayerContainer _players;
    std::vector<int> _board_choices = {4, 7, 11, 13, 17};

    std::vector<EdgeGraph*> _edge_graphs;
    std::vector<Field> _fields;

    int _board_size = 0;

    bool _next_move();
    bool _verify_move(std::pair<int, int>&, int&);
    void _create_player_src_dst_nodes();

  public:
    HexGame();
    ~HexGame();
};

#endif  // HEX_H_
