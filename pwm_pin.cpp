#include "pwm_pin.hpp"
#include "Arduino.h"


namespace ardent
{

pwm_pin::pwm_pin(int pin_number)
: pin(pin_number)
{
    pinMode(pin_number, OUTPUT);
}

void pwm_pin::set_duty_cycle(int duty_cycle)
{
    analogWrite(pin_number, duty_cycle);
}

}