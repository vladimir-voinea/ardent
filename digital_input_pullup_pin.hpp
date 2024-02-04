#pragma once

#include "digital_input_pin.hpp"

namespace ardent
{

class digital_input_pullup_pin : public digital_input_pin
{
public:
    digital_input_pullup_pin(int pin_number);
};

}