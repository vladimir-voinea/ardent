#include "digital_input_pin.hpp"
#include "Arduino.h"

digital_input_pin::digital_input_pin(int pin_number) 
: pin_number(pin_number)
{
    pinMode(pin_number, INPUT_PULLUP);
}

// void digital_pin::set_high()
// {
//     pinMode(pin_number, INPUT_PULLUP);
// }

// void digital_pin::set_low()
// {
//     pinMode(pin_number, INPUT);
// }

bool digital_input_pin::is_high() const
{
    return digitalRead(pin_number) == HIGH;
}

bool digital_input_pin::is_low() const
{
    return digitalRead(pin_number) == LOW;
}

int digital_input_pin::get_pin_number() const
{
    return pin_number;
}
