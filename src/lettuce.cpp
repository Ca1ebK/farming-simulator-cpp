#include <string>

#include "lettuce.hpp"

std::string Lettuce::symbol() {
  if(age < 2) {
    return "x";
  } else if (age < 4) {
    return "l";
  } else {
    return "L";
  }
}

void Lettuce::end_day() {
  if(watered) {
    age += 2;
  } else {
    age += 1;
  }
  watered = false;
}

void Lettuce::water() {
  watered = true;
}

bool Lettuce::is_harvestable() {
  return age >= 4;
}

int Lettuce::get_age() {
  return age;
}

