#include "led.hpp"
#include "Arduino.h"

namespace ardent
{
 
led::led(digital_output_pin pin)
: m_pin(pin)
{
}

void led::turn_on()
{
    m_pin.set_high();
}

void led::turn_off()
{
    m_pin.set_low();
}

}