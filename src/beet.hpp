#pragma once

#include <string>

#include "plot.hpp"

class Beet : public Plot {
  private:
    int age = 0;
    bool watered = false;

  public:
    std::string symbol() override;
    void end_day() override;
    void water() override;
    bool is_harvestable() override;
    int get_age();
};

