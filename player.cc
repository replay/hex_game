#include "./player.h"

Player::Player(GameStatus& game_status)
  : _game_status(game_status) {
}

void Player::set_color(Field::colors color) {
  _color = color;
}

Field::colors Player::get_color() {
  return _color;
}
