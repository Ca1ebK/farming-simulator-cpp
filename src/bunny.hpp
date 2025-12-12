#pragma once

class Bunny {
  private:
    int bunny_row;
    int bunny_column;
    bool scared;
    int scared_direction_row;
    int scared_direction_column;

  public:
    Bunny(int row, int column);
    int row();
    int column();
    bool is_scared();
    void set_scared(int player_row, int player_column);
    void move();
    void move_scared();
    bool is_on_farm(int max_rows, int max_columns);
};

