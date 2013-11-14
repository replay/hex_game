#include "./human_player.h"

HumanPlayer::HumanPlayer()
  : Player() {
  std::cout << "enter player's name: ";
  std::cin >> this->_player_name;
}


HumanPlayer::HumanPlayer(int id, const std::string player_name, const char symbol)
  : Player(id, player_name, symbol) {}

HumanPlayer::HumanPlayer(int id, const char* player_name, const char symbol)
  : Player(id, player_name, symbol) {}


int HumanPlayer::_get_coordinate(char coord) {
  std::string user_input("");

  while (!this->_is_numeric(user_input)) {
    std::cout << coord << ": ";
    std::cin >> user_input;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return std::stoi(user_input);
}

// ask the player for his next move
std::pair<int, int> HumanPlayer::get_move() {
  int x, y;

  x = this->_get_coordinate('x') - 1;
  y = this->_get_coordinate('y') - 1;

  return std::pair<int, int>(x, y);
}


// check if user's input is numeric
bool HumanPlayer::_is_numeric(std::string& s) {
  std::string::const_iterator i = s.begin();
  while (i != s.end() && std::isdigit(*i)) ++i;
  return !s.empty() && i == s.end();
}
