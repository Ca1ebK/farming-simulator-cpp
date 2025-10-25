#include "player.hpp"
#include <stdexcept>

Player::Player(int max_rows, int max_columns) : max_rows(max_rows), max_columns(max_columns) {
  if(max_rows <= 0 || max_columns <= 0) {
    throw std::invalid_argument("Farm dimensions must be positive");
  }
}

int Player::row() {
  return current_row;
}

int Player::column() {
  return current_column;
}

void Player::move_right() {
  if(current_column < max_columns - 1) {
    current_column += 1;
  }
}

void Player::move_down() {
  if(current_row < max_rows - 1) {
    current_row += 1;
  }
}

void Player::move_left() {
  if(current_column > 0) {
    current_column -= 1;
  }
}

void Player::move_up() {
  if(current_row > 0) {
    current_row -= 1;
  }
}