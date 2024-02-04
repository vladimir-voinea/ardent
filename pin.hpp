#pragma once

#include <stdint.h>

namespace ardent
{

class pin
{
public:
    pin(uint8_t pin_number);

    uint8_t get_pin_number() const;

protected:
    uint8_t pin_number;
};

}