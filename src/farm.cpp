#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "farm.hpp"
#include "soil.hpp"
#include "bunny.hpp"

Farm::Farm(int rows, int columns, Player *player, bool bunnies_enabled) : rows(rows), columns(columns), player(player), bunny(nullptr), bunnies_enabled(bunnies_enabled) {
  for(int i = 0; i < rows; i++) {
    std::vector<Plot *> row;
    for(int j = 0; j < columns; j++) {
      Soil *soil = new Soil();
      row.push_back(soil);
    }
    plots.push_back(row);
  }
  std::srand(std::time(nullptr));
}

int Farm::number_of_rows() {
  return rows;
}

int Farm::number_of_columns() {
  return columns;
}

std::string Farm::get_symbol(int row, int column) {
  if(player->row() == row && player->column() == column) {
    return "@";
  } else if(bunny != nullptr && bunny->row() == row && bunny->column() == column) {
    return "b";
  } else {
    return plots.at(row).at(column)->symbol();
  }
}

bool Farm::plant(int row, int column, Plot *plot) {
  Plot *current_plot = plots.at(row).at(column);
  if(current_plot->symbol() != ".") {
    return false;
  }
  plots.at(row).at(column) = plot;
  delete current_plot;
  return true;
}

void Farm::water(int row, int column) {
  Plot *current_plot = plots.at(row).at(column);
  current_plot->water();
}

bool Farm::harvest(int row, int column) {
  Plot *current_plot = plots.at(row).at(column);
  if(!current_plot->is_harvestable()) {
    return false;
  }
  plots.at(row).at(column) = new Soil();
  delete current_plot;
  return true;
}

bool Farm::is_bunny_at(int row, int column) {
  if(bunny == nullptr) {
    return false;
  }
  return bunny->row() == row && bunny->column() == column;
}

bool Farm::is_player_adjacent_to_bunny() {
  if(bunny == nullptr) {
    return false;
  }
  int player_row = player->row();
  int player_column = player->column();
  int bunny_row = bunny->row();
  int bunny_column = bunny->column();
  
  int row_diff = std::abs(player_row - bunny_row);
  int col_diff = std::abs(player_column - bunny_column);
  
  return (row_diff == 1 && col_diff == 0) || (row_diff == 0 && col_diff == 1);
}

void Farm::end_day() {
  if(bunny != nullptr) {
    int bunny_row = bunny->row();
    int bunny_column = bunny->column();
    
    if(bunny_row >= 0 && bunny_row < rows && bunny_column >= 0 && bunny_column < columns) {
      Plot *current_plot = plots.at(bunny_row).at(bunny_column);
      if(current_plot->symbol() != ".") {
        plots.at(bunny_row).at(bunny_column) = new Soil();
        delete current_plot;
      }
    }
    
    if(is_player_adjacent_to_bunny()) {
      bunny->set_scared(player->row(), player->column());
    }
    
    if(bunny->is_scared()) {
      bunny->move_scared();
    } else {
      bunny->move();
    }
    
    if(!bunny->is_on_farm(rows, columns)) {
      delete bunny;
      bunny = nullptr;
    } else {
      bunny_row = bunny->row();
      bunny_column = bunny->column();
      
      if(bunny_row == player->row() && bunny_column == player->column()) {
        bunny->move();
        if(!bunny->is_on_farm(rows, columns)) {
          delete bunny;
          bunny = nullptr;
        } else {
          bunny_row = bunny->row();
          bunny_column = bunny->column();
          if(bunny_row == player->row() && bunny_column == player->column()) {
            bunny->move();
            if(!bunny->is_on_farm(rows, columns)) {
              delete bunny;
              bunny = nullptr;
            }
          }
        }
      }
    }
  }
  
  if(bunnies_enabled && bunny == nullptr) {
    int spawn_chance = std::rand() % 100;
    if(spawn_chance < 50) {
      bunny = new Bunny(0, 0);
    }
  }
  
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      plots.at(i).at(j)->end_day();
    }
  }
}
