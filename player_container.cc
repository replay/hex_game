#include "./player_container.h"


PlayerContainer::~PlayerContainer() {
  for (auto p: this->_players)
    delete p;
}


bool PlayerContainer::add_player(Player* p) {
  if (this->_players.size() >= 2)
    return false;

  this->_players.push_back(p);

  return true;
}


void PlayerContainer::swap_active() {
  if (this->_currently_active == 0)
    this->_currently_active = 1;
  else
    this->_currently_active = 0;
}


void PlayerContainer::swap_player_position() {
  Player* p = this->_players[0];
  this->_players[0] = this->_players[1];
  this->_players[1] = p;
}


void PlayerContainer::set_virtual_start(int virtual_start) {
  this->_players[0]->set_src_dst_nodes(
      std::pair<int, int>(virtual_start, virtual_start + 1));
  this->_players[1]->set_src_dst_nodes(
      std::pair<int, int>(virtual_start + 2, virtual_start + 3));
}


int PlayerContainer::get_active_id() {
  return this->_currently_active;
}


char PlayerContainer::get_symbol(int p) {
  return this->_players[p]->get_symbol();
}
char PlayerContainer::get_symbol() {
  return this->_players[this->_currently_active]->get_symbol();
}


std::pair<int, int> PlayerContainer::get_src_dst_nodes(int p) {
  return this->_players[p]->get_src_dst_nodes();
}
std::pair<int, int> PlayerContainer::get_src_dst_nodes() {
  return this->_players[this->_currently_active]->get_src_dst_nodes();
}


std::pair<int, int> PlayerContainer::get_move(int p) {
  return this->_players[p]->get_move();
}
std::pair<int, int> PlayerContainer::get_move() {
  return this->_players[this->_currently_active]->get_move();
}


std::string PlayerContainer::get_name(int p) {
  return this->_players[p]->get_name();
}
std::string PlayerContainer::get_name() {
  return this->_players[this->_currently_active]->get_name();
}


std::vector<Player*>::iterator PlayerContainer::begin() {
  return this->_players.begin();
}
std::vector<Player*>::iterator PlayerContainer::end() {
  return this->_players.end();
}

