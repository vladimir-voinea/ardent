#pragma once

#include "digital_input_pullup_pin.hpp"

namespace ardent
{
 
class push_button
{
public:
    push_button(digital_input_pullup_pin pin);

    bool is_pressed() const;
    bool is_released() const;

    digital_input_pullup_pin get_pin() const;
    
private:
    digital_input_pullup_pin m_pin;
};

}