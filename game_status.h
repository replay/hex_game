#ifndef GAME_STATUS_H_
#define GAME_STATUS_H_

#include <vector>
#include <utility>
#include <map>
#include "./field.h"

class GameStatus {
  private:
    std::vector<Field> _fields;
    int _board_size;
    bool _finished=false;
    std::map<Field::colors, std::vector< std::pair< int, int > > > _edges;
    void _find_edges(int, Field::colors);
    void _add_edges(int, int, Field::colors);
    void _surrounding_hexagon(int, std::vector< std::pair<int, bool> >&);

  public:
    GameStatus(const int);
    int board_size();
    std::vector<Field>& field_ref();
    bool set_field(int, Field::colors);
    bool is_finished();
    void set_finished();
    bool has_winner();
};

#endif  // GAME_STATUS_H_
