#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/beet.hpp"

TEST_CASE( "it returns x when it is a seed" ) {
  Beet beet;
  REQUIRE( beet.symbol() == "x" );
}

TEST_CASE( "it returns b when the beet is a seedling" ) {
  Beet beet;
  beet.end_day();
  beet.end_day();
  REQUIRE( beet.symbol() == "b" );
}

TEST_CASE( "it returns B when the beet is mature" ) {
  Beet beet;
  for(int i = 0; i < 7; i++) {
    beet.end_day();
  }
  REQUIRE( beet.symbol() == "B" );
}

TEST_CASE( "it starts off with age 0" ) {
  Beet beet;
  REQUIRE( beet.get_age() == 0 );
}

TEST_CASE( "it has age 1 after we end the day one time" ) {
  Beet beet;
  beet.end_day();
  REQUIRE( beet.get_age() == 1 );
}

TEST_CASE( "it has age 7 after we end the day seven times" ) {
  Beet beet;
  for(int i = 0; i < 7; i++) {
    beet.end_day();
  }
  REQUIRE( beet.get_age() == 7 );
}

TEST_CASE( "it increases the age by 2 when we end the day after watering" ) {
  Beet beet;
  beet.water();
  beet.end_day();
  REQUIRE( beet.get_age() == 2 );
}

TEST_CASE( "watering more than once per day has no effect" ) {
  Beet beet;
  beet.water();
  beet.water();
  beet.end_day();
  REQUIRE( beet.get_age() == 2 );
}

TEST_CASE( "watering on a given day should not affect future days" ) {
  Beet beet;
  beet.water();
  beet.end_day();
  beet.end_day();
  REQUIRE( beet.get_age() == 3 );
}

TEST_CASE( "ages the beet properly after many waterings on many days" ) {
  Beet beet;
  beet.water();
  beet.end_day();
  beet.water();
  beet.end_day();
  REQUIRE( beet.get_age() == 4 );
}

