#include "digital_input_pin.hpp"
#include "Arduino.h"

namespace ardent
{

digital_input_pin::digital_input_pin(int pin_number) 
: pin(pin_number)
{
    pinMode(pin_number, INPUT);
}

bool digital_input_pin::is_high() const
{
    return digitalRead(pin_number) == HIGH;
}

bool digital_input_pin::is_low() const
{
    return digitalRead(pin_number) == LOW;
}


}