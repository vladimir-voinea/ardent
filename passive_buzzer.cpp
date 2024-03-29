#include "passive_buzzer.hpp"
#include "Arduino.h"

namespace ardent
{
passive_buzzer::passive_buzzer(digital_output_pin pin) : m_pin(pin)
{
}

void passive_buzzer::beep(frequency freq, ardent::milliseconds duration, std::function<void(void)> callback)
{
    if (is_muted())
    {
        return;
    }

    m_callback = std::move(callback);
    ::tone(m_pin.get_pin_number(), freq, duration.value);
    m_current_beep = current_beep_info{ardent::millis(), duration};
}

void passive_buzzer::start_beeping(frequency freq)
{
    if (is_muted())
    {
        return;
    }

    ::tone(m_pin.get_pin_number(), freq);
    m_current_beep = current_beep_info{ardent::millis(), ardent::milliseconds{0}};
}

void passive_buzzer::stop_beeping()
{
    ::noTone(m_pin.get_pin_number());
    m_current_beep = {{0}, {0}};
}

void passive_buzzer::update()
{
    if (std::get<0>(m_current_beep).value)
    {
        if (ardent::millis().value - std::get<0>(m_current_beep).value > std::get<1>(m_current_beep).value)
        {
            stop_beeping();
            if (m_callback)
            {
                m_callback();
                m_callback = {};
            }
        }
    }
    else if (std::get<0>(m_current_mute).value)
    {
        if (ardent::millis().value - std::get<0>(m_current_mute).value > std::get<1>(m_current_mute).value)
        {
            m_current_mute = {{0}, {0}};
            if (m_callback)
            {
                m_callback();
                m_callback = {};
            }
        }
    }
}

void passive_buzzer::mute(ardent::milliseconds duration, std::function<void(void)> callback)
{
    m_callback = std::move(callback);
    m_current_mute = current_beep_info{ardent::millis(), duration};
}

void passive_buzzer::mute()
{
    m_current_mute = {ardent::milliseconds{millis()}, ardent::milliseconds{~0u}};
}

void passive_buzzer::unmute()
{
    m_current_mute = {ardent::milliseconds{0}, ardent::milliseconds{0}};
}

bool passive_buzzer::is_beeping() const
{
    return std::get<0>(m_current_beep).value;
}

bool passive_buzzer::is_muted() const
{
    return std::get<0>(m_current_mute).value || std::get<1>(m_current_mute).value == ~0u;
}
} // namespace ardent