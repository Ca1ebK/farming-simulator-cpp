#include "bunny.hpp"

Bunny::Bunny(int row, int column) : bunny_row(row), bunny_column(column), scared(false), scared_direction_row(0), scared_direction_column(0) {}

int Bunny::row() {
  return bunny_row;
}

int Bunny::column() {
  return bunny_column;
}

bool Bunny::is_scared() {
  return scared;
}

void Bunny::set_scared(int player_row, int player_column) {
  scared = true;
  int row_diff = bunny_row - player_row;
  int col_diff = bunny_column - player_column;
  
  if(row_diff > 0) {
    scared_direction_row = 1;
  } else if(row_diff < 0) {
    scared_direction_row = -1;
  } else {
    scared_direction_row = 0;
  }
  
  if(col_diff > 0) {
    scared_direction_column = 1;
  } else if(col_diff < 0) {
    scared_direction_column = -1;
  } else {
    scared_direction_column = 0;
  }
  
  if(scared_direction_row == 0 && scared_direction_column == 0) {
    scared_direction_column = 1;
  }
}

void Bunny::move() {
  bunny_column += 1;
}

void Bunny::move_scared() {
  for(int i = 0; i < 4; i++) {
    bunny_row += scared_direction_row;
    bunny_column += scared_direction_column;
  }
  scared = false;
}

bool Bunny::is_on_farm(int max_rows, int max_columns) {
  return bunny_row >= 0 && bunny_row < max_rows && bunny_column >= 0 && bunny_column < max_columns;
}

