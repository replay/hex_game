#include "./player.h"


// different types of constructors
Player::Player() {}

Player::Player(const std::string player_name, const char symbol)
  : _player_name(player_name),
    _symbol(symbol) {}

Player::Player(const char* player_name, const char symbol)
  : _player_name(player_name),
    _symbol(symbol) {}


// set the player's name
void Player::set_name(std::string name) {
  this->_player_name = name;
}


// get the player's name
std::string Player::get_name() {
  return this->_player_name;
}


// get the symbol that's used to show that a field belongs to this player
char Player::get_symbol() {
  return this->_symbol;
}


// set the symbol that's used to show that a field belongs to this player
void Player::set_symbol(const char symbol) {
  this->_symbol = symbol;
}


// set the node numbers of the two virtual nodes that are used to check if
// this player has won the game
void Player::set_src_dst_nodes(std::pair<int, int> src_dst) {
  this->_src_dst = src_dst;
}


// get the node numbers of the two virtual nodes that are used to check if
// this player has won the game
std::pair<int, int> Player::get_src_dst_nodes() {
  return this->_src_dst;
}


// print the player's name to represent the object
std::ostream& operator<< (std::ostream& os, Player* player) {
  return os << player->get_name();
}
