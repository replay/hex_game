#include "./human_player.h"

HumanPlayer::HumanPlayer(GameStatus& game_status)
  : Player(game_status) {
}

move_t HumanPlayer::get_move() {
  move_t move = move_t(2, 3);
  return move;
}
