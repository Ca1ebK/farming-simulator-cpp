#include <string>
#include <vector>
#include <stdexcept>

#include "farm.hpp"
#include "soil.hpp"

Farm::Farm(int rows, int columns, Player *player) : rows(rows), columns(columns), player(player) {
  if(player == nullptr) {
    throw std::invalid_argument("Player pointer cannot be null");
  }
  if(rows <= 0 || columns <= 0) {
    throw std::invalid_argument("Farm dimensions must be positive");
  }
  for(int i = 0; i < rows; i++) {
    std::vector<Plot *> row;
    for(int j = 0; j < columns; j++) {
      Soil *soil = new Soil();
      row.push_back(soil);
    }
    plots.push_back(row);
  }
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
  } else {
    return plots.at(row).at(column)->symbol();
  }
}

bool Farm::plant(int row, int column, Plot *plot) {
  Plot *current_plot = plots.at(row).at(column);
  
  if(!current_plot->is_soil()) {
    delete plot;  // Clean up the new plot since we can't plant here
    return false;
  }
  
  // Only assign and delete if we passed the soil check
  plots.at(row).at(column) = plot;
  delete current_plot;
  return true;
}

bool Farm::harvest(int row, int column) {
  Plot *current_plot = plots.at(row).at(column);
  
  if(!current_plot->is_harvestable()) {
    return false;
  }
  
  // Replace with new soil
  Soil *new_soil = new Soil();
  plots.at(row).at(column) = new_soil;
  delete current_plot;
  return true;
}

void Farm::end_day() {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      plots.at(i).at(j)->end_day();
    }
  }
}

Farm::~Farm() {
  // Clean up all plots in the farm
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      delete plots.at(i).at(j);
    }
  }
}
