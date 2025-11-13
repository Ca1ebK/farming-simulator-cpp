#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
  if(age == 0) {
    return "v";
  } else if (age <= 2) {
    return "V";
  } else {
    return "W";
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

int Carrot::get_age() {
  return age;
}
