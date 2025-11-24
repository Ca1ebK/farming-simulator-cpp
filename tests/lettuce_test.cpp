#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/lettuce.hpp"

TEST_CASE( "it returns x when it is a seed" ) {
  Lettuce lettuce;
  REQUIRE( lettuce.symbol() == "x" );
}

TEST_CASE( "it returns l when the lettuce is a seedling" ) {
  Lettuce lettuce;
  lettuce.end_day();
  lettuce.end_day();
  REQUIRE( lettuce.symbol() == "l" );
}

TEST_CASE( "it returns L when the lettuce is mature" ) {
  Lettuce lettuce;
  lettuce.end_day();
  lettuce.end_day();
  lettuce.end_day();
  lettuce.end_day();
  REQUIRE( lettuce.symbol() == "L" );
}

TEST_CASE( "it starts off with age 0" ) {
  Lettuce lettuce;
  REQUIRE( lettuce.get_age() == 0 );
}

TEST_CASE( "it has age 1 after we end the day one time" ) {
  Lettuce lettuce;
  lettuce.end_day();
  REQUIRE( lettuce.get_age() == 1 );
}

TEST_CASE( "it has age 4 after we end the day four times" ) {
  Lettuce lettuce;
  lettuce.end_day();
  lettuce.end_day();
  lettuce.end_day();
  lettuce.end_day();
  REQUIRE( lettuce.get_age() == 4 );
}

TEST_CASE( "it increases the age by 2 when we end the day after watering" ) {
  Lettuce lettuce;
  lettuce.water();
  lettuce.end_day();
  REQUIRE( lettuce.get_age() == 2 );
}

TEST_CASE( "watering more than once per day has no effect" ) {
  Lettuce lettuce;
  lettuce.water();
  lettuce.water();
  lettuce.end_day();
  REQUIRE( lettuce.get_age() == 2 );
}

TEST_CASE( "watering on a given day should not affect future days" ) {
  Lettuce lettuce;
  lettuce.water();
  lettuce.end_day();
  lettuce.end_day();
  REQUIRE( lettuce.get_age() == 3 );
}

TEST_CASE( "ages the lettuce properly after many waterings on many days" ) {
  Lettuce lettuce;
  lettuce.water();
  lettuce.end_day();
  lettuce.water();
  lettuce.end_day();
  REQUIRE( lettuce.get_age() == 4 );
}

