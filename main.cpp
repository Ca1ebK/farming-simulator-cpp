#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"

int main() {
  Player player;
  Farm farm(7, 8, &player);
  FarmPrinter printer(&farm);
  bool game_in_progress = true;
  std::string player_input;

  while(game_in_progress) {
    ansi_clear();
    std::cout << printer.pp() << std::endl;
    std::cout << "=== Game Controls ===" << std::endl;
    std::cout << "Move: W / A / S / D" << std::endl;
    std::cout << "Plant: C" << std::endl;
    std::cout << "Water: T" << std::endl;
    std::cout << "End Day: E" << std::endl;
    std::cout << "Exit Game: Q" << std::endl;
    std::cout << "=====================" << std::endl;
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
      farm.plant(player.row(), player.column(), carrot);
    } else if(player_input == "t") {
      farm.water(player.row(), player.column());
    } else if(player_input == "e") {
      farm.end_day();
    }
  }
}
