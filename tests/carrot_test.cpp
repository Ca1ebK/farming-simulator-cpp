#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE( "it returns a v as its symbol when it is a seedling" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "v" );
}

TEST_CASE( "it returns a V when the carrot is half-grown after one day" ) {
  Carrot carrot;
  carrot.end_day();
  REQUIRE( carrot.symbol() == "V" );
}

TEST_CASE( "it returns a W when the carrot is fully grown after two days" ) {
  Carrot carrot;
  carrot.end_day();
  carrot.end_day();
  REQUIRE( carrot.symbol() == "W" );
}

TEST_CASE( "it remains fully grown after additional days" ) {
  Carrot carrot;
  carrot.end_day();
  carrot.end_day();
  carrot.end_day();
  REQUIRE( carrot.symbol() == "W" );
}

TEST_CASE( "it maintains consistent interface across growth stages" ) {
  Carrot carrot;
  REQUIRE( !carrot.symbol().empty() );
  
  carrot.end_day();
  REQUIRE( !carrot.symbol().empty() );
  
  carrot.end_day();
  REQUIRE( !carrot.symbol().empty() );
}

TEST_CASE( "it progresses through all growth stages" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "v" );
  
  carrot.end_day();
  REQUIRE( carrot.symbol() == "V" );
  
  carrot.end_day();
  REQUIRE( carrot.symbol() == "W" );
}

TEST_CASE( "it starts as a seedling" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "v" );
}

TEST_CASE( "it is not harvestable as a seedling" ) {
  Carrot carrot;
  REQUIRE( carrot.is_harvestable() == false );
}

TEST_CASE( "it is not harvestable when half-grown" ) {
  Carrot carrot;
  carrot.end_day();
  REQUIRE( carrot.is_harvestable() == false );
}

TEST_CASE( "it is harvestable when fully grown" ) {
  Carrot carrot;
  carrot.end_day();
  carrot.end_day();
  REQUIRE( carrot.is_harvestable() == true );
}

TEST_CASE( "it remains harvestable after additional days" ) {
  Carrot carrot;
  carrot.end_day();
  carrot.end_day();
  carrot.end_day();
  REQUIRE( carrot.is_harvestable() == true );
}
