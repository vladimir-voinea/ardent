#pragma once

#include "digital_output_pin.hpp"

class led
{
public:
  led(digital_output_pin pin);
  void turn_on();
  void turn_off();

private:
  digital_output_pin m_pin;
};