#pragma once

#include "pin.hpp"

namespace ardent
{
    
class pwm_pin : public pin
{
public:
    pwm_pin(int pin_number);

    void set_duty_cycle(int duty_cycle);
};

}