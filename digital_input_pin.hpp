#pragma once

#include "pin.hpp"

namespace ardent
{

class digital_input_pin : public pin
{
public:
    digital_input_pin(int pin_number);

    virtual bool is_high() const;
    virtual bool is_low() const;
};

}