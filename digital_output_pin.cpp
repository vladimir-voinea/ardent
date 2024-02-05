#include "digital_output_pin.hpp"
#include "Arduino.h"

namespace ardent
{

digital_output_pin::digital_output_pin(uint8_t pin_number) : pin(pin_number)
{
    ::pinMode(pin_number, OUTPUT);
}

void digital_output_pin::set_high()
{
    ::digitalWrite(pin_number, HIGH);
}

void digital_output_pin::set_low()
{
    ::digitalWrite(pin_number, LOW);
}

} // namespace ardent