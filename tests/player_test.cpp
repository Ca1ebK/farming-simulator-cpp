#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"

TEST_CASE( "it starts the player in row zero, column zero" ) {
  Player player(2, 2);
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player to the right" ) {
  Player player(2, 2);
  player.move_right();
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 1 );
}

TEST_CASE( "it moves the player down" ) {
  Player player(2, 2);
  player.move_down();
  REQUIRE( player.row() == 1 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player to the left" ) {
  Player player(2, 2);
  player.move_right();
  player.move_left();
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player up" ) {
  Player player(2, 2);
  player.move_down();
  player.move_up();
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it prevents moving right beyond boundaries" ) {
  Player player(2, 2);
  player.move_right();
  player.move_right();
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 1 );
}

TEST_CASE( "it prevents moving down beyond boundaries" ) {
  Player player(2, 2);
  player.move_down();
  player.move_down();
  REQUIRE( player.row() == 1 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it prevents moving left beyond boundaries" ) {
  Player player(2, 2);
  player.move_left();
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it prevents moving up beyond boundaries" ) {
  Player player(2, 2);
  player.move_up();
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it maintains consistent position interface" ) {
  Player player(3, 3);
  
  REQUIRE( player.row() >= 0 );
  REQUIRE( player.column() >= 0 );
  REQUIRE( player.row() < 3 );
  REQUIRE( player.column() < 3 );
  
  player.move_right();
  player.move_down();
  REQUIRE( player.row() >= 0 );
  REQUIRE( player.column() >= 0 );
  REQUIRE( player.row() < 3 );
  REQUIRE( player.column() < 3 );
}

TEST_CASE( "it handles complex movement sequences" ) {
  Player player(3, 3);
  
  player.move_right();
  player.move_down();
  player.move_left();
  player.move_up();
  player.move_right();
  player.move_right();
  
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 2 );
}

TEST_CASE( "it initializes player at origin" ) {
  Player player(1, 1);
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 0 );
}