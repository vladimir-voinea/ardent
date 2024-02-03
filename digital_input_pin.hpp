#pragma once

namespace ardent
{

class digital_input_pin
{
public:
    digital_input_pin(int pin_number);

    bool is_high() const;
    bool is_low() const;

    int get_pin_number() const;
private:
    int pin_number;
};

}