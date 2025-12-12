#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/bunny.hpp"

TEST_CASE( "it initializes at the given position" ) {
  Bunny bunny(5, 3);
  REQUIRE( bunny.row() == 5 );
  REQUIRE( bunny.column() == 3 );
}

TEST_CASE( "it moves one square to the right" ) {
  Bunny bunny(0, 0);
  bunny.move();
  REQUIRE( bunny.row() == 0 );
  REQUIRE( bunny.column() == 1 );
}

TEST_CASE( "it is not scared initially" ) {
  Bunny bunny(0, 0);
  REQUIRE( bunny.is_scared() == false );
}

TEST_CASE( "it becomes scared when set" ) {
  Bunny bunny(5, 5);
  bunny.set_scared(4, 5);
  REQUIRE( bunny.is_scared() == true );
}

TEST_CASE( "it moves four squares away when scared" ) {
  Bunny bunny(5, 5);
  bunny.set_scared(4, 5);
  bunny.move_scared();
  REQUIRE( bunny.row() == 9 );
  REQUIRE( bunny.column() == 5 );
}

TEST_CASE( "it reports being on farm when within bounds" ) {
  Bunny bunny(3, 4);
  REQUIRE( bunny.is_on_farm(10, 10) == true );
}

TEST_CASE( "it reports not being on farm when outside bounds" ) {
  Bunny bunny(10, 5);
  REQUIRE( bunny.is_on_farm(10, 10) == false );
}

