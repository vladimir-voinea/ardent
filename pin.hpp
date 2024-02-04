#pragma once

#include <stddef.h>

namespace ardent
{

class pin
{
public:
    pin(uint8_t pin_number);

    int get_pin_number() const;

protected:
    uint8_t pin_number;
};

}