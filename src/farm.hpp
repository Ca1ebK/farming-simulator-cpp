#pragma once

#include <string>
#include <vector>

#include "plot.hpp"
#include "player.hpp"

class Farm {
  private:
    int rows;
    int columns;
    Player *player;
    std::vector<std::vector<Plot *>> plots;

  public:
    Farm(int rows, int columns, Player *player);
    int number_of_rows();
    int number_of_columns();
    std::string get_symbol(int row, int column);
    bool plant(int row, int column, Plot *plot);
    bool harvest(int row, int column);
    void end_day();
    ~Farm();
};
