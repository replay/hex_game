#ifndef HEX_H_
#define HEX_H_

#include <iostream>

#include "./hex_board.h"
#include "./edge_graph.h"
#include "./human_player.h"

class HexGame {
  private:
    EdgeGraph _edge_graph;

    Player* _player1;
    Player* _player2;

    std::vector<Field> _fields;
    Field::colors _winner;
    bool _finished = false;
    int _board_size;

    Field::colors _get_winner();
    bool _next_move(Player&);
    bool _has_winner();

  public:
    HexGame(int = 11);
    ~HexGame();
};

#endif  // HEX_H_
