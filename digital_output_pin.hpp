#pragma once

#include "i_output_pin.hpp"
#include "pin.hpp"

namespace ardent
{

class digital_output_pin final : public pin, public i_output_pin
{
  public:
    digital_output_pin(uint8_t pin_number);

    void set_high() override;
    void set_low() override;
};

} // namespace ardent