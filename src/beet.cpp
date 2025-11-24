#include <string>

#include "beet.hpp"

std::string Beet::symbol() {
  if(age < 2) {
    return "x";
  } else if (age < 7) {
    return "b";
  } else {
    return "B";
  }
}

void Beet::end_day() {
  if(watered) {
    age += 2;
  } else {
    age += 1;
  }
  watered = false;
}

void Beet::water() {
  watered = true;
}

bool Beet::is_harvestable() {
  return age >= 7;
}

int Beet::get_age() {
  return age;
}

