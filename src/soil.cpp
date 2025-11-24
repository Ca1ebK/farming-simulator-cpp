#include "soil.hpp"

std::string Soil::symbol() {
  return ".";
}

void Soil::end_day() {
  // no-op
}

void Soil::water() {
  // no-op
}

bool Soil::is_harvestable() {
  return false;
}