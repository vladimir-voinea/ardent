#pragma once

#include "digital_input_pin.hpp"

namespace ardent
{

class digital_input_pullup_pin final : public digital_input_pin
{
  public:
    digital_input_pullup_pin(uint8_t pin_number);
};

} // namespace ardent