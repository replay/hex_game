#ifndef GAME_STATUS_H_
#define GAME_STATUS_H_

#include <vector>
#include <utility>
#include "./field.h"

class GameStatus {
  private:
    std::vector<Field> _fields;
    int _board_size;
    void _initialize_board_fields();
  public:
    GameStatus(const int);
    int board_size();
    std::vector<Field>& field_ref();
    bool set_field(int, Field::colors);
    bool is_finished();
};

#endif  // GAME_STATUS_H_
