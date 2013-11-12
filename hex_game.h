#ifndef HEX_H_
#define HEX_H_

#include <iostream>
#include <algorithm>
#include <vector>

#include "./types.h"
#include "./ascii_art.h"
#include "./hex_board.h"
#include "./edge_graph.h"
#include "./human_player.h"

class HexGame {
  private:
    EdgeGraph* _edge_graph;
    std::vector<Player*> _players;

    std::vector<Field> _fields;
    bool _finished = false;
    int _board_size = 0;

    bool _next_move(Player&);
    bool _has_winner();
    void _create_player_src_dst_nodes();
    Player* _swap_player(Player*);

  public:
    HexGame();
    ~HexGame();
};

#endif  // HEX_H_
