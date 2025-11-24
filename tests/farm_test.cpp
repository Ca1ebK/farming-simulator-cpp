#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"
#include "../src/farm.hpp"
#include "../src/carrot.hpp"
#include "../src/lettuce.hpp"
#include "../src/spinach.hpp"
#include "../src/beet.hpp"
#include "../src/brusselssprouts.hpp"

TEST_CASE( "it can be initialized with a single plot" ) {
  Player player;
  Farm farm(1, 1, &player);
  REQUIRE( farm.number_of_rows() == 1 );
  REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it can be initialized as a 1x2 farm" ) {
  Player player;
  Farm farm(1, 2, &player);
  REQUIRE( farm.number_of_rows() == 1 );
  REQUIRE( farm.number_of_columns() == 2 );
}

TEST_CASE( "it can be initialized as a 2x1 farm" ) {
  Player player;
  Farm farm(2, 1, &player);
  REQUIRE( farm.number_of_rows() == 2 );
  REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it returns the symbol for a single soil plot" ) {
  Player player;
  Farm farm(1, 1, &player);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
}

TEST_CASE( "it returns the symbols for a 1x2 farm" ) {
  Player player;
  Farm farm(1, 2, &player);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it returns the symbols for a 2x1 farm" ) {
  Player player;
  Farm farm(2, 1, &player);
  REQUIRE( farm.get_symbol(0, 0) == "@" );
  REQUIRE( farm.get_symbol(1, 0) == "." );
}

TEST_CASE( "it allows us to plant a carrot" ) {
  Player player;
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  REQUIRE( farm.get_symbol(0, 1) == "x" );
}

TEST_CASE( "it allows us to plant a lettuce" ) {
  Player player;
  Farm farm(1, 2, &player);
  Lettuce *lettuce = new Lettuce();
  farm.plant(0, 1, lettuce);
  REQUIRE( farm.get_symbol(0, 1) == "x" );
}

TEST_CASE( "it allows us to plant a spinach" ) {
  Player player;
  Farm farm(1, 2, &player);
  Spinach *spinach = new Spinach();
  farm.plant(0, 1, spinach);
  REQUIRE( farm.get_symbol(0, 1) == "x" );
}

TEST_CASE( "it allows us to plant a beet" ) {
  Player player;
  Farm farm(1, 2, &player);
  Beet *beet = new Beet();
  farm.plant(0, 1, beet);
  REQUIRE( farm.get_symbol(0, 1) == "x" );
}

TEST_CASE( "it allows us to plant brussels sprouts" ) {
  Player player;
  Farm farm(1, 2, &player);
  BrusselsSprouts *brusselssprouts = new BrusselsSprouts();
  farm.plant(0, 1, brusselssprouts);
  REQUIRE( farm.get_symbol(0, 1) == "x" );
}

TEST_CASE( "it does not allow planting on an existing plant" ) {
  Player player;
  Farm farm(1, 2, &player);
  Carrot *carrot1 = new Carrot();
  Carrot *carrot2 = new Carrot();
  farm.plant(0, 1, carrot1);
  bool result = farm.plant(0, 1, carrot2);
  REQUIRE( result == false );
  delete carrot2;
}

TEST_CASE( "it allows us to water a carrot" ) {
  Player player;
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  farm.water(0, 1);
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "V" );
}

TEST_CASE( "it allows us to water a lettuce" ) {
  Player player;
  Farm farm(1, 2, &player);
  Lettuce *lettuce = new Lettuce();
  farm.plant(0, 1, lettuce);
  farm.water(0, 1);
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "l" );
}

TEST_CASE( "carrot grows from seed to seedling after one day" ) {
  Player player;
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "v" );
}

TEST_CASE( "carrot grows from seedling to mature after two days" ) {
  Player player;
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  farm.end_day();
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "V" );
}

TEST_CASE( "lettuce grows from seed to seedling after two days" ) {
  Player player;
  Farm farm(1, 2, &player);
  Lettuce *lettuce = new Lettuce();
  farm.plant(0, 1, lettuce);
  farm.end_day();
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "l" );
}

TEST_CASE( "lettuce grows from seedling to mature after four days" ) {
  Player player;
  Farm farm(1, 2, &player);
  Lettuce *lettuce = new Lettuce();
  farm.plant(0, 1, lettuce);
  for(int i = 0; i < 4; i++) {
    farm.end_day();
  }
  REQUIRE( farm.get_symbol(0, 1) == "L" );
}

TEST_CASE( "spinach grows from seed to seedling after two days" ) {
  Player player;
  Farm farm(1, 2, &player);
  Spinach *spinach = new Spinach();
  farm.plant(0, 1, spinach);
  farm.end_day();
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "s" );
}

TEST_CASE( "spinach grows from seedling to mature after five days" ) {
  Player player;
  Farm farm(1, 2, &player);
  Spinach *spinach = new Spinach();
  farm.plant(0, 1, spinach);
  for(int i = 0; i < 5; i++) {
    farm.end_day();
  }
  REQUIRE( farm.get_symbol(0, 1) == "S" );
}

TEST_CASE( "beet grows from seed to seedling after two days" ) {
  Player player;
  Farm farm(1, 2, &player);
  Beet *beet = new Beet();
  farm.plant(0, 1, beet);
  farm.end_day();
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "b" );
}

TEST_CASE( "beet grows from seedling to mature after seven days" ) {
  Player player;
  Farm farm(1, 2, &player);
  Beet *beet = new Beet();
  farm.plant(0, 1, beet);
  for(int i = 0; i < 7; i++) {
    farm.end_day();
  }
  REQUIRE( farm.get_symbol(0, 1) == "B" );
}

TEST_CASE( "brussels sprouts grows from seed to seedling after five days" ) {
  Player player;
  Farm farm(1, 2, &player);
  BrusselsSprouts *brusselssprouts = new BrusselsSprouts();
  farm.plant(0, 1, brusselssprouts);
  for(int i = 0; i < 5; i++) {
    farm.end_day();
  }
  REQUIRE( farm.get_symbol(0, 1) == "u" );
}

TEST_CASE( "brussels sprouts grows from seedling to mature after fifteen days" ) {
  Player player;
  Farm farm(1, 2, &player);
  BrusselsSprouts *brusselssprouts = new BrusselsSprouts();
  farm.plant(0, 1, brusselssprouts);
  for(int i = 0; i < 15; i++) {
    farm.end_day();
  }
  REQUIRE( farm.get_symbol(0, 1) == "U" );
}

TEST_CASE( "it allows harvesting a mature carrot" ) {
  Player player;
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  farm.end_day();
  farm.end_day();
  bool result = farm.harvest(0, 1);
  REQUIRE( result == true );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it does not allow harvesting a carrot seedling" ) {
  Player player;
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  farm.end_day();
  bool result = farm.harvest(0, 1);
  REQUIRE( result == false );
  REQUIRE( farm.get_symbol(0, 1) == "v" );
}

TEST_CASE( "it does not allow harvesting a carrot seed" ) {
  Player player;
  Farm farm(1, 2, &player);
  Carrot *carrot = new Carrot();
  farm.plant(0, 1, carrot);
  bool result = farm.harvest(0, 1);
  REQUIRE( result == false );
  REQUIRE( farm.get_symbol(0, 1) == "x" );
}

TEST_CASE( "it allows harvesting a mature lettuce" ) {
  Player player;
  Farm farm(1, 2, &player);
  Lettuce *lettuce = new Lettuce();
  farm.plant(0, 1, lettuce);
  for(int i = 0; i < 4; i++) {
    farm.end_day();
  }
  bool result = farm.harvest(0, 1);
  REQUIRE( result == true );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it does not allow harvesting a lettuce seedling" ) {
  Player player;
  Farm farm(1, 2, &player);
  Lettuce *lettuce = new Lettuce();
  farm.plant(0, 1, lettuce);
  farm.end_day();
  farm.end_day();
  bool result = farm.harvest(0, 1);
  REQUIRE( result == false );
  REQUIRE( farm.get_symbol(0, 1) == "l" );
}

TEST_CASE( "it allows harvesting a mature spinach" ) {
  Player player;
  Farm farm(1, 2, &player);
  Spinach *spinach = new Spinach();
  farm.plant(0, 1, spinach);
  for(int i = 0; i < 5; i++) {
    farm.end_day();
  }
  bool result = farm.harvest(0, 1);
  REQUIRE( result == true );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it allows harvesting a mature beet" ) {
  Player player;
  Farm farm(1, 2, &player);
  Beet *beet = new Beet();
  farm.plant(0, 1, beet);
  for(int i = 0; i < 7; i++) {
    farm.end_day();
  }
  bool result = farm.harvest(0, 1);
  REQUIRE( result == true );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it allows harvesting a mature brussels sprouts" ) {
  Player player;
  Farm farm(1, 2, &player);
  BrusselsSprouts *brusselssprouts = new BrusselsSprouts();
  farm.plant(0, 1, brusselssprouts);
  for(int i = 0; i < 15; i++) {
    farm.end_day();
  }
  bool result = farm.harvest(0, 1);
  REQUIRE( result == true );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it does not allow harvesting soil" ) {
  Player player;
  Farm farm(1, 2, &player);
  bool result = farm.harvest(0, 1);
  REQUIRE( result == false );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "end_day affects all plots on the farm" ) {
  Player player;
  Farm farm(2, 2, &player);
  Carrot *carrot1 = new Carrot();
  Carrot *carrot2 = new Carrot();
  Lettuce *lettuce = new Lettuce();
  farm.plant(0, 1, carrot1);
  farm.plant(1, 0, carrot2);
  farm.plant(1, 1, lettuce);
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "v" );
  REQUIRE( farm.get_symbol(1, 0) == "v" );
  REQUIRE( farm.get_symbol(1, 1) == "x" );
}

TEST_CASE( "watering affects growth speed for all vegetables" ) {
  Player player;
  Farm farm(1, 3, &player);
  Carrot *carrot = new Carrot();
  Lettuce *lettuce = new Lettuce();
  farm.plant(0, 1, carrot);
  farm.plant(0, 2, lettuce);
  farm.water(0, 1);
  farm.water(0, 2);
  farm.end_day();
  REQUIRE( farm.get_symbol(0, 1) == "V" );
  REQUIRE( farm.get_symbol(0, 2) == "l" );
}