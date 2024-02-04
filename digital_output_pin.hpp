#pragma once

#include "pin.hpp"

namespace ardent
{
 
class digital_output_pin : public pin
{
public:
    digital_output_pin(int pin_number);

    void set_high();
    void set_low();
};

}