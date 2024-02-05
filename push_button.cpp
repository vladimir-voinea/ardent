#include "push_button.hpp"

namespace ardent
{

push_button::push_button(digital_input_pullup_pin pin) : m_pin(pin)
{
}

push_button::reading_type push_button::read() const
{
    return m_pin.is_low();
}

bool push_button::is_pressed() const
{
    return m_pin.is_low();
}

bool push_button::is_released() const
{
    return m_pin.is_high();
}

digital_input_pullup_pin push_button::get_pin() const
{
    return m_pin;
}

} // namespace ardent