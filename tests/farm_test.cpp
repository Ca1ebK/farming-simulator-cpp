#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"
#include "../src/farm.hpp"
#include "../src/carrot.hpp"
#include "../src/soil.hpp"

TEST_CASE( "it can be initialized with a single plot" ) {
  Player player(1, 1);
  Farm farm(1, 1, &player);
  REQUIRE( farm.number_of_rows() == 1 );
  REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it can be initialized as a 1x2 farm" ) {
  Player player(1, 2);
  Farm farm(1, 2, &player);
  REQUIRE( farm.number_of_rows() == 1 );
  REQUIRE( farm.number_of_columns() == 2 );
}

TEST_CASE( "it can be initialized as a 2x1 farm" ) {
  Player player(2, 1);
  Farm farm(2, 1, &player);
  REQUIRE( farm.number_of_rows() == 2 );
  REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it returns the symbol for a single soil plot" ) {
  Player player(1, 1);
  Farm farm(1, 1, &player);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
}

TEST_CASE( "it returns the symbols for a 1x2 farm" ) {
  Player player(1, 2);
  Farm farm(1, 2, &player);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it returns the symbols for a 2x1 farm" ) {
  Player player(2, 1);
  Farm farm(2, 1, &player);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
  REQUIRE( farm.get_symbol(1, 0) == "." );
}

TEST_CASE( "it allows us to plant a carrot" ) {
  Player player(1, 2);
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  REQUIRE( farm.get_symbol(0, 1) == "v" );
}

TEST_CASE( "it handles different farm sizes consistently" ) {
  std::vector<std::tuple<int, int, int, int>> test_cases = {
    {1, 1, 1, 1}, {1, 2, 1, 2}, {2, 1, 2, 1}, {2, 2, 2, 2}
  };
  
  for (auto& test_case : test_cases) {
    int rows = std::get<0>(test_case);
    int cols = std::get<1>(test_case);
    int expected_rows = std::get<2>(test_case);
    int expected_cols = std::get<3>(test_case);
    
    Player player(rows, cols);
    Farm farm(rows, cols, &player);
    REQUIRE( farm.number_of_rows() == expected_rows );
    REQUIRE( farm.number_of_columns() == expected_cols );
  }
}

TEST_CASE( "it provides consistent symbol interface" ) {
  Player player(2, 2);
  Farm farm(2, 2, &player);
  
  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 2; col++) {
      std::string symbol = farm.get_symbol(row, col);
      REQUIRE( !symbol.empty() );
      REQUIRE( (symbol == "@" || symbol == ".") );
    }
  }
}

TEST_CASE( "it handles planting and growth operations" ) {
  Player player(2, 2);
  Farm farm(2, 2, &player);
  Carrot *carrot = new Carrot();
  
  farm.plant(1, 1, carrot);
  REQUIRE( farm.get_symbol(1, 1) == "v" );
  
  REQUIRE( farm.get_symbol(0, 0) == "@" );
  REQUIRE( farm.get_symbol(0, 1) == "." );
  REQUIRE( farm.get_symbol(1, 0) == "." );
}

TEST_CASE( "it creates a farm with correct dimensions" ) {
  Player player(1, 1);
  Farm farm(1, 1, &player);
  REQUIRE( farm.number_of_rows() == 1 );
  REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it can harvest a mature carrot" ) {
  Player player(1, 2);
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  farm.end_day();
  farm.end_day();
  REQUIRE( farm.harvest(0, 1) == true );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it cannot harvest from soil" ) {
  Player player(1, 1);
  Farm farm(1, 1, &player);
  REQUIRE( farm.harvest(0, 0) == false );
}

TEST_CASE( "it cannot harvest a seedling carrot" ) {
  Player player(1, 1);
  Farm farm(1, 1, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 0, carrot);
  REQUIRE( farm.harvest(0, 0) == false );
}

TEST_CASE( "it cannot harvest a half-grown carrot" ) {
  Player player(1, 1);
  Farm farm(1, 1, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 0, carrot);
  farm.end_day();
  REQUIRE( farm.harvest(0, 0) == false );
}

TEST_CASE( "it returns soil after harvesting" ) {
  Player player(1, 2);
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  farm.end_day();
  farm.end_day();
  farm.harvest(0, 1);
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it allows planting after harvesting" ) {
  Player player(1, 1);
  Farm farm(1, 1, &player);
  Carrot *carrot1 = new Carrot();
  farm.plant(0, 0, carrot1);
  farm.end_day();
  farm.end_day();
  farm.harvest(0, 0);
  
  Carrot *carrot2 = new Carrot();
  REQUIRE( farm.plant(0, 0, carrot2) == true );
}