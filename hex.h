#ifndef HEX_H_
#define HEX_H_

#include <iostream>

#include "./board_printer.h"
#include "./edge_graph.h"
#include "./human_player.h"

typedef class illegal_move_exception: public std::exception {
} illegal_move_exception;

class Hex {
  private:
    EdgeGraph _edge_graph;

    Player* _player1;
    Player* _player2;

    std::vector<Field> _fields;
    Field::colors _winner;
    bool _finished = false;
    int _board_size;

    Field::colors _get_winner();
    int _move_to_fieldnum(move_t);
    void _move(Player&);
    bool _is_finished();
    bool _has_winner();
    bool _set_field(int, Field::colors);
    void _build_paths();

  public:
    Hex(int = 11);
    ~Hex();
};

#endif  // HEX_H_
