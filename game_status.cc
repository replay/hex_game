#include "./game_status.h"

void GameStatus::_initialize_board_fields() {
  _fields.resize(_board_size * _board_size);
}

GameStatus::GameStatus(const int board_size)
  : _board_size(board_size) {
  _initialize_board_fields();
}

int GameStatus::board_size() {
  return _board_size;
}

std::vector<Field>& GameStatus::field_ref() {
  return _fields;
}

bool GameStatus::is_finished() {
  return false;
}

bool GameStatus::set_field(int field, Field::colors color) {
  if (_fields[field].get_color() == Field::colors::EMPTY) {
    _fields[field].set_color(color);
  } else{
    return false;
  }

  return true;
}

