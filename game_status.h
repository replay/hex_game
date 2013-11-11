#ifndef GAME_STATUS_H_
#define GAME_STATUS_H_

#include <vector>
#include <utility>
#include <map>
#include "./field.h"
#include "./edge_graph.h"

class GameStatus {
  private:
    std::vector<Field> _fields;
    EdgeGraph _edge_graph;
    int _board_size;
    bool _finished = false;
    Field::colors _winner = Field::colors::EMPTY;
    void _find_edges(int, Field::colors);
    void _add_edges(int, int, Field::colors);
    void _surrounding_hexagon(int, std::vector< std::pair<int, bool> >&);
    void _build_paths();

  public:
    GameStatus(const int);
    int board_size();
    std::vector<Field>& field_ref();
    bool set_field(int, Field::colors);
    bool is_finished();
    void set_finished();
    bool has_winner();
    Field::colors get_winner();
};

#endif  // GAME_STATUS_H_
