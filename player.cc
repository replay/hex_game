#include "./player.h"

Player::Player(GameStatus& game_status)
  : _game_status(game_status) {}

Player::Player(GameStatus& game_status, const std::string player_name)
  : _game_status(game_status),
    _player_name(player_name) {}

Player::Player(GameStatus& game_status, const char* player_name)
  : _game_status(game_status),
    _player_name(player_name) {}

void Player::set_color(Field::colors color) {
  this->_color = color;
}

Field::colors Player::get_color() {
  return this->_color;
}

void Player::set_player_name(std::string name) {
  this->_player_name = name;
}

std::string Player::get_player_name() {
  return this->_player_name;
}

std::ostream& operator<< (std::ostream& os, Player* player) {
  return os << player->get_player_name();
}
