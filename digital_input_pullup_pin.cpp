#include "digital_input_pullup_pin.hpp"
#include "Arduino.h"

namespace ardent
{

digital_input_pullup_pin::digital_input_pullup_pin(uint8_t pin_number) : digital_input_pin(pin_number)
{
    ::pinMode(pin_number, INPUT_PULLUP);
}

} // namespace ardent