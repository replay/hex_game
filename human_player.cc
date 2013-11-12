#include "./human_player.h"

HumanPlayer::HumanPlayer()
  : Player() {
  std::cout << "enter player's name: ";
  std::cin >> this->_player_name;
}

HumanPlayer::HumanPlayer(const std::string player_name)
  : Player(player_name) {}

HumanPlayer::HumanPlayer(const char* player_name)
  : Player(player_name) {}

move_t HumanPlayer::get_move() {
  int x, y;
  std::string user_input("");

  std::cout << "enter the coordinates of your next move: " << std::endl;
  while (!this->_is_numeric(user_input)) {
    std::cout << "x: ";
    std::cin >> user_input;
  }
  x = std::stoi(user_input) - 1;

  user_input = std::string("");
  while (!this->_is_numeric(user_input)) {
    std::cout << "y: ";
    std::cin >> user_input;
  }
  y = std::stoi(user_input) - 1;

  return move_t(x, y);
}

bool HumanPlayer::_is_numeric(std::string& s) {
  std::string::const_iterator i = s.begin();
  while (i != s.end() && std::isdigit(*i)) ++i;
  return !s.empty() && i == s.end();
}