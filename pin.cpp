#include "pin.hpp"

namespace ardent
{

pin::pin(int pin_number)
: pin_number(pin_number)
{}

int pin::get_pin_number() const
{
    return pin_number;
}

}