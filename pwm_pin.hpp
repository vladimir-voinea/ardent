#pragma once

#include "i_output_pin.hpp"
#include "pin.hpp"

namespace ardent
{

class pwm_pin final : public pin, public i_output_pin
{
  public:
    pwm_pin(int pin_number);

    void set_duty_cycle(int duty_cycle);
    void set_high() override;
    void set_low() override;
};

} // namespace ardent