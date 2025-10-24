#pragma once

class Player {
  private:
    int current_row = 0;
    int current_column = 0;
    int max_rows;
    int max_columns;

  public:
    Player(int max_rows, int max_columns);
    int row();
    int column();
    void move_right();
    void move_down();
    void move_left();
    void move_up();
};
