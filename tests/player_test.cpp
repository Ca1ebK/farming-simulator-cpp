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
  player.move_right(); // column 1
  player.move_right(); // should not move beyond column 1
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 1 );
}

TEST_CASE( "it prevents moving down beyond boundaries" ) {
  Player player(2, 2);
  player.move_down(); // row 1
  player.move_down(); // should not move beyond row 1
  REQUIRE( player.row() == 1 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it prevents moving left beyond boundaries" ) {
  Player player(2, 2);
  player.move_left(); // should not move beyond column 0
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it prevents moving up beyond boundaries" ) {
  Player player(2, 2);
  player.move_up(); // should not move beyond row 0
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 0 );
}