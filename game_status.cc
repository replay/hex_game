#include "./game_status.h"

GameStatus::GameStatus(const int board_size)
  : _board_size(board_size),
    _edge_graph(EdgeGraph(board_size, this->_fields)) {
  this->_fields.resize(this->_board_size * this->_board_size);
}

void GameStatus::_build_paths() {
}

int GameStatus::board_size() {
  return this->_board_size;
}

std::vector<Field>& GameStatus::field_ref() {
  return this->_fields;
}

bool GameStatus::is_finished() {
  return this->_finished;
}

void GameStatus::set_finished() {
  this->_finished = true;
}

bool GameStatus::set_field(int field, Field::colors color) {
  if (field < 0)
    return false;
  if (field >= this->_fields.size())
    return false;
  if (this->_fields[field].get_color() != Field::colors::EMPTY)
    return false;

  this->_fields[field].set_color(color);
  this->_edge_graph.update_edges(field, color);
  return true;
}

Field::colors GameStatus::get_winner() {
  return this->_winner;
}

bool GameStatus::has_winner() {
  this->_build_paths();

  for (int i = 0; i < this->_board_size; ++i) {
    for (int j = 0; j < this->_board_size; ++j) {
      if (this->_edge_graph.find_path(i, (this->_board_size - 1) * this->_board_size + j, Field::colors::BLACK))
        this->_winner = Field::colors::BLACK;
        return true;
    }
  }

  for (int i = 0; i < this->_board_size; ++i) {
    for (int j = 0; j < this->_board_size; ++j) {
      if (this->_edge_graph.find_path(
        i * this->_board_size, j * this->_board_size + this->_board_size - 1,
        Field::colors::BLACK)) {
        this->_winner = Field::colors::BLACK;
        return true;
      }
    }
  }

  return false;
}
