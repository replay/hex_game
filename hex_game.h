#ifndef HEX_H_
#define HEX_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <tuple>

#include "./types.h"
#include "./field.h"
#include "./ascii_art.h"
#include "./hex_board.h"
#include "./edge_graph.h"
#include "./human_player.h"

class HexGame {
  private:
    std::vector<Player*> _players;
    std::map< int, std::pair<EdgeGraph*, board_direction> > _player_data;
    std::vector<Field> _fields;

    int _board_size = 0;

    bool _verify_move(std::pair<int, int>&, int&);
    bool _next_move(Player&);
    void _create_player_src_dst_nodes();
    Player* _swap_player(Player*);

  public:
    HexGame();
    ~HexGame();
};

#endif  // HEX_H_
