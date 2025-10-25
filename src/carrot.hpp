#pragma once

#include <string>

#include "plot.hpp"

class Carrot : public Plot {
  private:
    int age = 0;

  public:
    std::string symbol() override;
    void end_day() override;
    bool is_soil() override;
    bool is_harvestable() override;
};
