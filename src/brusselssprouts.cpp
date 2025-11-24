#include <string>

#include "brusselssprouts.hpp"

std::string BrusselsSprouts::symbol() {
  if(age < 5) {
    return "x";
  } else if (age < 15) {
    return "u";
  } else {
    return "U";
  }
}

void BrusselsSprouts::end_day() {
  if(watered) {
    age += 2;
  } else {
    age += 1;
  }
  watered = false;
}

void BrusselsSprouts::water() {
  watered = true;
}

bool BrusselsSprouts::is_harvestable() {
  return age >= 15;
}

int BrusselsSprouts::get_age() {
  return age;
}

