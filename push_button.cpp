#include "push_button.hpp"

push_button::push_button(digital_input_pin pin)
: m_pin(pin)
{
}

bool push_button::is_pressed() const
{
    return m_pin.is_low();
}

bool push_button::is_released() const
{
    return m_pin.is_high();
}

digital_input_pin push_button::get_pin() const
{
    return m_pin;
}