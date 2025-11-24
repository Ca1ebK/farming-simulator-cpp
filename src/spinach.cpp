#include <string>

#include "spinach.hpp"

std::string Spinach::symbol() {
  if(age < 2) {
    return "x";
  } else if (age < 5) {
    return "s";
  } else {
    return "S";
  }
}

void Spinach::end_day() {
  if(watered) {
    age += 2;
  } else {
    age += 1;
  }
  watered = false;
}

void Spinach::water() {
  watered = true;
}

bool Spinach::is_harvestable() {
  return age >= 5;
}

int Spinach::get_age() {
  return age;
}

