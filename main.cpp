#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/lettuce.hpp"
#include "src/spinach.hpp"
#include "src/beet.hpp"
#include "src/brusselssprouts.hpp"
#include "src/ansi_clear.hpp"

int main() {

  int current_day = 1;
  Player player(7, 8);
  Farm farm(7, 8, &player);
  FarmPrinter printer(&farm);
  bool game_in_progress = true;
  char player_input;

  while(game_in_progress) {
    ansi_clear();
    std::cout << "Day " << current_day << std::endl;
    std::cout << "=== Game Controls ===" << std::endl;
    std::cout << "Move: W / A / S / D" << std::endl;
    std::cout << "Plant Carrot: C" << std::endl;
    std::cout << "Plant Lettuce: L" << std::endl;
    std::cout << "Plant Spinach: P" << std::endl;
    std::cout << "Plant Beet: B" << std::endl;
    std::cout << "Plant Brussels Sprouts: U" << std::endl;
    std::cout << "Harvest: H" << std::endl;
    std::cout << "Water: T" << std::endl;
    std::cout << "End Day: E" << std::endl;
    std::cout << "Exit Game: Q" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << printer.pp() << std::endl;
    std::cin >> player_input;

    if(player_input == 'q') {
      game_in_progress = false;
    } else if(player_input == 'd') {
      int target_row = player.row();
      int target_column = player.column() + 1;
      if(!farm.is_bunny_at(target_row, target_column)) {
        player.move_right();
      }
    } else if(player_input == 's') {
      int target_row = player.row() + 1;
      int target_column = player.column();
      if(!farm.is_bunny_at(target_row, target_column)) {
        player.move_down();
      }
    } else if(player_input == 'a') {
      int target_row = player.row();
      int target_column = player.column() - 1;
      if(!farm.is_bunny_at(target_row, target_column)) {
        player.move_left();
      }
    } else if(player_input == 'w') {
      int target_row = player.row() - 1;
      int target_column = player.column();
      if(!farm.is_bunny_at(target_row, target_column)) {
        player.move_up();
      }
    } else if(player_input == 'c') {
      Carrot *carrot = new Carrot();
      if(!farm.plant(player.row(), player.column(), carrot)) {
        delete carrot;
        std::cout << "Cannot plant on existing seed or plant" << std::endl;
      }
    } else if(player_input == 'l') {
      Lettuce *lettuce = new Lettuce();
      if(!farm.plant(player.row(), player.column(), lettuce)) {
        delete lettuce;
        std::cout << "Cannot plant on existing seed or plant" << std::endl;
      }
    } else if(player_input == 'p') {
      Spinach *spinach = new Spinach();
      if(!farm.plant(player.row(), player.column(), spinach)) {
        delete spinach;
        std::cout << "Cannot plant on existing seed or plant" << std::endl;
      }
    } else if(player_input == 'b') {
      Beet *beet = new Beet();
      if(!farm.plant(player.row(), player.column(), beet)) {
        delete beet;
        std::cout << "Cannot plant on existing seed or plant" << std::endl;
      }
    } else if(player_input == 'u') {
      BrusselsSprouts *brusselssprouts = new BrusselsSprouts();
      if(!farm.plant(player.row(), player.column(), brusselssprouts)) {
        delete brusselssprouts;
        std::cout << "Cannot plant on existing seed or plant" << std::endl;
      }
    } else if(player_input == 'h') {
      if(!farm.harvest(player.row(), player.column())) {
        std::cout << "Cannot harvest non-adult plant" << std::endl;
      }
    } else if(player_input == 't') {
      farm.water(player.row(), player.column());
    } else if(player_input == 'e') {
      farm.end_day();
      current_day++;
    }
  }
}
