#include "./player_container.h"


// free memory that was allocated for all players
PlayerContainer::~PlayerContainer() {
  for (auto p: this->_players)
    delete p;
}


// get the next symbol that isn't assigned to a player yet
char PlayerContainer::_get_free_symbol() {
  switch (this->_players.size() + 1) {
    case (1):
      return 'O';
      break;
    case (2):
      return 'X';
      break;
  }
}


// make the other player active and the current player inactive. should be
// called at the end of each round to give the next round to the other player
void PlayerContainer::swap_active() {
  if (this->_currently_active == 0)
    this->_currently_active = 1;
  else
    this->_currently_active = 0;
}


// swap the position of the existing players inside the internal vector
void PlayerContainer::swap_player_position() {
  Player* p = this->_players[0];
  this->_players[0] = this->_players[1];
  this->_players[1] = p;
}


// set starting node number for virtual fields that are not shown on the board
void PlayerContainer::set_virtual_start(int virtual_start) {
  this->_players[0]->set_src_dst_nodes(
      std::pair<int, int>(virtual_start, virtual_start + 1));
  this->_players[1]->set_src_dst_nodes(
      std::pair<int, int>(virtual_start + 2, virtual_start + 3));
}


// create a player and add it to the internal vector of players
int PlayerContainer::create_player(
  const char* player_name_c, const player_type type) {
  Player* player;
  std::string player_name (player_name_c);

  // create a player object according to the given type
  switch(type) {
    case (player_type::HUMAN):
      player = new HumanPlayer(player_name, this->_get_free_symbol());
      break;
  }

  this->_players.push_back(player);

  // return how many player currently exist
  return this->_players.size();
}


// get symbol of a given player number or currently active player
char PlayerContainer::get_symbol(int p) {
  return this->_players[p]->get_symbol();
}
char PlayerContainer::get_symbol() {
  return this->_players[this->_currently_active]->get_symbol();
}


// get id of currently active player
int PlayerContainer::get_active_id() {
  return this->_currently_active;
}


// get the two virtual nodes of a given player or the currently active player
std::pair<int, int> PlayerContainer::get_src_dst_nodes(int p) {
  return this->_players[p]->get_src_dst_nodes();
}
std::pair<int, int> PlayerContainer::get_src_dst_nodes() {
  return this->_players[this->_currently_active]->get_src_dst_nodes();
}


// get the next move from the player object of a given player number or from
// the currently active one
std::pair<int, int> PlayerContainer::get_move(int p) {
  return this->_players[p]->get_move();
}
std::pair<int, int> PlayerContainer::get_move() {
  return this->_players[this->_currently_active]->get_move();
}


// get the name of a given player number or the currently active one
std::string PlayerContainer::get_name(int p) {
  return this->_players[p]->get_name();
}
std::string PlayerContainer::get_name() {
  return this->_players[this->_currently_active]->get_name();
}


// get a vector of all existing player names
std::vector<std::string> PlayerContainer::get_all_player_names() {
  return std::accumulate(
    this->_players.begin(), this->_players.end(),
    std::vector<std::string>(), [](std::vector<std::string>& v, Player* p) {
      v.push_back(p->get_name());
      return v;
    }
  );
}
