#include "pin.hpp"

namespace ardent
{

pin::pin(uint8_t pin_number)
: pin_number(pin_number)
{}

uint8_t pin::get_pin_number() const
{
    return pin_number;
}

}