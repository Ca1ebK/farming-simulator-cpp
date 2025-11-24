#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/spinach.hpp"

TEST_CASE( "it returns x when it is a seed" ) {
  Spinach spinach;
  REQUIRE( spinach.symbol() == "x" );
}

TEST_CASE( "it returns s when the spinach is a seedling" ) {
  Spinach spinach;
  spinach.end_day();
  spinach.end_day();
  REQUIRE( spinach.symbol() == "s" );
}

TEST_CASE( "it returns S when the spinach is mature" ) {
  Spinach spinach;
  spinach.end_day();
  spinach.end_day();
  spinach.end_day();
  spinach.end_day();
  spinach.end_day();
  REQUIRE( spinach.symbol() == "S" );
}

TEST_CASE( "it starts off with age 0" ) {
  Spinach spinach;
  REQUIRE( spinach.get_age() == 0 );
}

TEST_CASE( "it has age 1 after we end the day one time" ) {
  Spinach spinach;
  spinach.end_day();
  REQUIRE( spinach.get_age() == 1 );
}

TEST_CASE( "it has age 5 after we end the day five times" ) {
  Spinach spinach;
  spinach.end_day();
  spinach.end_day();
  spinach.end_day();
  spinach.end_day();
  spinach.end_day();
  REQUIRE( spinach.get_age() == 5 );
}

TEST_CASE( "it increases the age by 2 when we end the day after watering" ) {
  Spinach spinach;
  spinach.water();
  spinach.end_day();
  REQUIRE( spinach.get_age() == 2 );
}

TEST_CASE( "watering more than once per day has no effect" ) {
  Spinach spinach;
  spinach.water();
  spinach.water();
  spinach.end_day();
  REQUIRE( spinach.get_age() == 2 );
}

TEST_CASE( "watering on a given day should not affect future days" ) {
  Spinach spinach;
  spinach.water();
  spinach.end_day();
  spinach.end_day();
  REQUIRE( spinach.get_age() == 3 );
}

TEST_CASE( "ages the spinach properly after many waterings on many days" ) {
  Spinach spinach;
  spinach.water();
  spinach.end_day();
  spinach.water();
  spinach.end_day();
  REQUIRE( spinach.get_age() == 4 );
}

