#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE( "it returns a v as its when it is a seedling" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "v" );
}

TEST_CASE( "it returns a V when the carrot is half-grown" ) {
  Carrot carrot;
  carrot.end_day();
  REQUIRE( carrot.symbol() == "V" );
}

TEST_CASE( "it returns a W when the carrot is fully grown" ) {
  Carrot carrot;
  carrot.end_day();
  carrot.end_day();
  REQUIRE( carrot.symbol() == "W" );
}

TEST_CASE( "it starts off with age 0" ) {
  Carrot carrot;
  REQUIRE( carrot.get_age() == 0 );
}

TEST_CASE( "it has age 1 after we end the day one time" ) {
  Carrot carrot;
  carrot.end_day();
  REQUIRE( carrot.get_age() == 1 );
}

TEST_CASE( "it has age 2 after we end the day twice" ) {
  Carrot carrot;
  carrot.end_day();
  carrot.end_day();
  REQUIRE( carrot.get_age() == 2 );
}

TEST_CASE( "it increases the age by 2 when we end the day after watering" ) {
  Carrot carrot;
  carrot.water();
  carrot.end_day();
  REQUIRE( carrot.get_age() == 2 );
}

TEST_CASE( "watering more than once per day has no effect" ) {
  Carrot carrot;
  carrot.water();
  carrot.water();
  carrot.end_day();
  REQUIRE( carrot.get_age() == 2 );
}

TEST_CASE( "watering on a given day should not affect future days" ) {
  Carrot carrot;
  carrot.water();
  carrot.end_day();
  carrot.end_day();
  REQUIRE( carrot.get_age() == 3 );
}

TEST_CASE( "ages the carrot properly after many waterings on many days" ) {
  Carrot carrot;
  carrot.water();
  carrot.end_day();
  carrot.water();
  carrot.end_day();
  REQUIRE( carrot.get_age() == 4 );
}
