#pragma once

#include "digital_input_pin.hpp"

class push_button
{
public:
    push_button(digital_input_pin pin);

    bool is_pressed() const;
    bool is_released() const;

    digital_input_pin get_pin() const;
    
private:
    digital_input_pin m_pin;
};