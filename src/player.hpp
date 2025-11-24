#pragma once

class Player {
  private:
    int current_row = 0;
    int current_column = 0;
    int max_rows = 100;
    int max_columns = 100;

  public:
    Player();
    Player(int rows, int columns);
    int row();
    int column();
    void move_right();
    void move_down();
    void move_left();
    void move_up();
};
