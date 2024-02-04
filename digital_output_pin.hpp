#pragma once

#include "pin.hpp"

namespace ardent
{
 
class digital_output_pin final : public pin
{
public:
    digital_output_pin(uint8_t pin_number);

    void set_high();
    void set_low();
};

}