#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/soil.hpp"

TEST_CASE( "it returns a dot as its symbol" ) {
  Soil soil;
  REQUIRE( soil.symbol() == "." );
}

TEST_CASE( "end_day is a no-op" ) {
  Soil soil;
  soil.end_day();
  REQUIRE( soil.symbol() == "." );
}

TEST_CASE( "it remains unchanged after multiple end_day calls" ) {
  Soil soil;
  soil.end_day();
  soil.end_day();
  soil.end_day();
  REQUIRE( soil.symbol() == "." );
}

TEST_CASE( "it handles repeated operations consistently" ) {
  Soil soil;
  std::string initial_symbol = soil.symbol();
  
  for (int i = 0; i < 10; i++) {
    soil.end_day();
    REQUIRE( soil.symbol() == initial_symbol );
  }
}

TEST_CASE( "it maintains consistent interface" ) {
  Soil soil;
  
  REQUIRE( !soil.symbol().empty() );
  REQUIRE( soil.symbol() == "." );
  
  soil.end_day();
  REQUIRE( !soil.symbol().empty() );
  REQUIRE( soil.symbol() == "." );
}

TEST_CASE( "it behaves consistently across all operations" ) {
  Soil soil;
  
  REQUIRE( soil.symbol() == "." );
  
  soil.end_day();
  REQUIRE( soil.symbol() == "." );
  
  soil.end_day();
  soil.end_day();
  REQUIRE( soil.symbol() == "." );
}

TEST_CASE( "it has a simple dot symbol" ) {
  Soil soil;
  REQUIRE( soil.symbol() == "." );
}

TEST_CASE( "it is never harvestable" ) {
  Soil soil;
  REQUIRE( soil.is_harvestable() == false );
}

TEST_CASE( "it remains not harvestable after operations" ) {
  Soil soil;
  soil.end_day();
  soil.end_day();
  REQUIRE( soil.is_harvestable() == false );
}