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
        m_current_beep = current_beep_info{ardent::millis(), duration};
    }

    void passive_buzzer::start_beeping(frequency freq)
    {
        ::tone(m_pin.get_pin_number(), freq);
        m_current_beep = current_beep_info{ardent::millis(), 0};
    }

    void passive_buzzer::stop_beeping()
    {
        ::noTone(m_pin.get_pin_number());
        m_current_beep = {};
    }

    void passive_buzzer::update()
    {
        if(m_current_beep.has_value())
        {
            const auto& [start_time, duration] = m_current_beep.value();
            if(ardent::millis().value - start_time.value > duration.value)
            {
                stop_beeping();
            }
        }
        return i_loop_observer::action::none;
    }
}