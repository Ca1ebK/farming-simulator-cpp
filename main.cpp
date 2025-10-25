#include <iostream>
#include <vector>
#include <stdexcept>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"

int main() {
  Player player(7, 8);
  Farm farm(7, 8, &player);
  FarmPrinter printer(&farm);
  int current_day = 1;
  bool game_in_progress = true;
  std::string player_input;

  while(game_in_progress) {
    ansi_clear();
    std::cout << "Day " << current_day << std::endl;
    std::cout << printer.pp() << std::endl;
    std::cin >> player_input;

    if(player_input == "q") {
      game_in_progress = false;
    } else if(player_input == "d") {
      player.move_right();
    } else if(player_input == "s") {
      player.move_down();
    } else if(player_input == "a") {
      player.move_left();
    } else if(player_input == "w") {
      player.move_up();
    } else if(player_input == "c") {
      Carrot *carrot = new Carrot();
      if(!farm.plant(player.row(), player.column(), carrot)) {
        std::cout << "Cannot plant on a carrot" << std::endl;
      }
    } else if(player_input == "e") {
      farm.end_day();
      current_day++;
    } else if(player_input == "h") {
      if(!farm.harvest(player.row(), player.column())) {
        std::cout << "Cannot harvest a non-adult carrot" << std::endl;
      }
    }
  }
}
