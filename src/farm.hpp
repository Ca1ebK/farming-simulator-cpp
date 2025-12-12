#pragma once

#include <string>
#include <vector>

#include "plot.hpp"
#include "player.hpp"

class Bunny;

class Farm {
  private:
    int rows;
    int columns;
    Player *player;
    std::vector<std::vector<Plot *>> plots;
    Bunny *bunny;
    bool bunnies_enabled;
    bool is_player_adjacent_to_bunny();

  public:
    Farm(int rows, int columns, Player *player, bool bunnies_enabled = true);
    int number_of_rows();
    int number_of_columns();
    std::string get_symbol(int row, int column);
    void water(int row, int column);
    bool plant(int row, int column, Plot *plot);
    bool harvest(int row, int column);
    void end_day();
    bool is_bunny_at(int row, int column);
};
