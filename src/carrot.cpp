#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
  if(age == 0) {
    return "x";
  } else if (age == 1) {
    return "v";
  } else {
    return "V";
  }
}

void Carrot::end_day() {
  if(watered) {
    age += 2;
  } else {
    age += 1;
  }
  watered = false;
}

void Carrot::water() {
  watered = true;
}

bool Carrot::is_harvestable() {
  return age >= 2;
}

int Carrot::get_age() {
  return age;
}
