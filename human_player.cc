#include "./human_player.h"

HumanPlayer::HumanPlayer(GameStatus& game_status)
  : Player(game_status) {
}

move_t HumanPlayer::get_move() {
  return move_t(2, 3);
}
