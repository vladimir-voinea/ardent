#pragma once

#include <push_button.hpp>
#include <time.hpp>
#include <sleep.hpp>

namespace ardent
{

template <typename TCallback>
class debounced_button
{
public:
    debounced_button(push_button button, TCallback&& press_callback)
    : m_button(button)
    , m_press_callback(press_callback)
    {}

    void update()
    {
        if (m_button.is_pressed() && !m_last_button_state)
        {
            m_last_pressed_time = ardent::millis();
            m_last_button_state = true;
        }
        else if (!m_button.is_pressed() && m_last_button_state)
        {
            if (ardent::millis().value - m_last_pressed_time.value > m_debounce_delay.value)
            {
                m_press_callback();
                m_last_button_state = false;
            }
        }        
    }

    void set_debounce_delay(estd::milliseconds delay)
    {
        m_debounce_delay = delay;
    }

    estd::milliseconds get_debounce_delay() const
    {
        return m_debounce_delay;
    }

    push_button get_button() const
    {
        return m_button;
    }

private:
    push_button m_button;
    TCallback m_press_callback;
    estd::milliseconds m_last_pressed_time;
    estd::milliseconds m_debounce_delay = estd::milliseconds{50};
    bool m_last_button_state;
};
}