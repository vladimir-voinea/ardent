#pragma once

class digital_input_pin
{
public:
    digital_input_pin(int pin_number);

    // void set_high();
    // void set_low();

    //void toggle();

    bool is_high() const;
    bool is_low() const;

    int get_pin_number() const;
private:
    int pin_number;
};