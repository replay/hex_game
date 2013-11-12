#include "./player.h"

Player::Player() {}

Player::Player(const std::string player_name)
  : _player_name(player_name) {}

Player::Player(const char* player_name)
  : _player_name(player_name) {}

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
