#include "digital_output_pin.hpp"
#include "Arduino.h"

digital_output_pin::digital_output_pin(int pin_number)
: pin_number(pin_number)
{
    pinMode(pin_number, OUTPUT);
}

void digital_output_pin::set_high()
{
    digitalWrite(pin_number, HIGH);
}

void digital_output_pin::set_low()
{
    digitalWrite(pin_number, LOW);
}

int digital_output_pin::get_pin_number() const
{
    return pin_number;
}