#include "./player.h"

Player::Player() {}


Player::Player(int id, const std::string player_name, const char symbol)
  : _id(id),
    _player_name(player_name),
    _symbol(symbol) {}

Player::Player(int id, const char* player_name, const char symbol)
  : _id(id),
    _player_name(player_name),
    _symbol(symbol) {}

void Player::set_name(std::string name) {
  this->_player_name = name;
}

std::string Player::get_name() {
  return this->_player_name;
}

char Player::get_symbol() {
  return this->_symbol;
}

void Player::set_symbol(const char symbol) {
  this->_symbol = symbol;
}

int Player::get_id() {
  return this->_id;
}

void Player::set_src_dst_nodes(std::pair<int, int> src_dst) {
  this->_src_dst = src_dst;
}

std::pair<int, int> Player::get_src_dst_nodes() {
  return this->_src_dst;
}

std::ostream& operator<< (std::ostream& os, Player* player) {
  return os << player->get_name();
}
