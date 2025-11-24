#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/brusselssprouts.hpp"

TEST_CASE( "it returns x when it is a seed" ) {
  BrusselsSprouts brusselssprouts;
  REQUIRE( brusselssprouts.symbol() == "x" );
}

TEST_CASE( "it returns u when the brussels sprouts is a seedling" ) {
  BrusselsSprouts brusselssprouts;
  for(int i = 0; i < 5; i++) {
    brusselssprouts.end_day();
  }
  REQUIRE( brusselssprouts.symbol() == "u" );
}

TEST_CASE( "it returns U when the brussels sprouts is mature" ) {
  BrusselsSprouts brusselssprouts;
  for(int i = 0; i < 15; i++) {
    brusselssprouts.end_day();
  }
  REQUIRE( brusselssprouts.symbol() == "U" );
}

TEST_CASE( "it starts off with age 0" ) {
  BrusselsSprouts brusselssprouts;
  REQUIRE( brusselssprouts.get_age() == 0 );
}

TEST_CASE( "it has age 1 after we end the day one time" ) {
  BrusselsSprouts brusselssprouts;
  brusselssprouts.end_day();
  REQUIRE( brusselssprouts.get_age() == 1 );
}

TEST_CASE( "it has age 15 after we end the day fifteen times" ) {
  BrusselsSprouts brusselssprouts;
  for(int i = 0; i < 15; i++) {
    brusselssprouts.end_day();
  }
  REQUIRE( brusselssprouts.get_age() == 15 );
}

TEST_CASE( "it increases the age by 2 when we end the day after watering" ) {
  BrusselsSprouts brusselssprouts;
  brusselssprouts.water();
  brusselssprouts.end_day();
  REQUIRE( brusselssprouts.get_age() == 2 );
}

TEST_CASE( "watering more than once per day has no effect" ) {
  BrusselsSprouts brusselssprouts;
  brusselssprouts.water();
  brusselssprouts.water();
  brusselssprouts.end_day();
  REQUIRE( brusselssprouts.get_age() == 2 );
}

TEST_CASE( "watering on a given day should not affect future days" ) {
  BrusselsSprouts brusselssprouts;
  brusselssprouts.water();
  brusselssprouts.end_day();
  brusselssprouts.end_day();
  REQUIRE( brusselssprouts.get_age() == 3 );
}

TEST_CASE( "ages the brussels sprouts properly after many waterings on many days" ) {
  BrusselsSprouts brusselssprouts;
  brusselssprouts.water();
  brusselssprouts.end_day();
  brusselssprouts.water();
  brusselssprouts.end_day();
  REQUIRE( brusselssprouts.get_age() == 4 );
}

