#pragma once

#include "digital_output_pin.hpp"
#include "i_led.hpp"

namespace ardent
{

class led final : public i_led
{
  public:
    led(digital_output_pin pin);
    void turn_on() override;
    void turn_off() override;

  private:
    digital_output_pin m_pin;
};

} // namespace ardent