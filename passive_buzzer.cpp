#include "passive_buzzer.hpp"
#include "Arduino.h"

namespace ardent
{
    passive_buzzer::passive_buzzer(digital_output_pin pin) 
    : m_pin(pin)
    {
    }

    void passive_buzzer::beep(frequency freq, estd::milliseconds duration)
    {
        ::tone(m_pin.get_pin_number(), freq, duration.value);
    }

    void passive_buzzer::start_beeping(frequency freq)
    {
        ::tone(m_pin.get_pin_number(), freq);
    }

    void passive_buzzer::stop_beeping()
    {
        ::noTone(m_pin.get_pin_number());
    }
}