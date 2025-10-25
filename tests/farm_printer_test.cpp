#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"
#include "../src/farm.hpp"
#include "../src/farm_printer.hpp"

TEST_CASE( "it pretty prints a single plot of land" ) {
  Player player(1, 1);
  Farm farm(1, 1, &player);
  FarmPrinter printer(&farm);
  REQUIRE( printer.pp() == "@ \n" );
}

TEST_CASE( "it pretty prints a 1x2 farm" ) {
  Player player(1, 2);
  Farm farm(1, 2, &player);
  FarmPrinter printer(&farm);
  REQUIRE( printer.pp() == "@ . \n" );
}

TEST_CASE( "it pretty prints a 2x1 farm" ) {
  Player player(2, 1);
  Farm farm(2, 1, &player);
  FarmPrinter printer(&farm);
  REQUIRE( printer.pp() == "@ \n. \n" );
}

TEST_CASE( "it pretty prints a 2x2 farm" ) {
  Player player(2, 2);
  Farm farm(2, 2, &player);
  FarmPrinter printer(&farm);
  REQUIRE( printer.pp() == "@ . \n. . \n" );
}

TEST_CASE( "it handles different farm sizes consistently" ) {
  Player player1(1, 1);
  Farm farm1(1, 1, &player1);
  FarmPrinter printer1(&farm1);
  REQUIRE( !printer1.pp().empty() );
  
  Player player2(3, 3);
  Farm farm2(3, 3, &player2);
  FarmPrinter printer2(&farm2);
  REQUIRE( !printer2.pp().empty() );
}

TEST_CASE( "it provides consistent output format" ) {
  Player player(2, 2);
  Farm farm(2, 2, &player);
  FarmPrinter printer(&farm);
  std::string output = printer.pp();
  
  REQUIRE( output.find("@") != std::string::npos );
  REQUIRE( output.find(".") != std::string::npos );
  REQUIRE( output.find("\n") != std::string::npos );
}

TEST_CASE( "it handles various farm configurations" ) {
  std::vector<std::pair<int, int>> sizes = {{1,1}, {1,2}, {2,1}, {2,2}};
  
  for (auto& size : sizes) {
    Player player(size.first, size.second);
    Farm farm(size.first, size.second, &player);
    FarmPrinter printer(&farm);
    REQUIRE( !printer.pp().empty() );
  }
}

TEST_CASE( "it creates a printer for any farm" ) {
  Player player(1, 1);
  Farm farm(1, 1, &player);
  FarmPrinter printer(&farm);
  REQUIRE( printer.pp() == "@ \n" );
}