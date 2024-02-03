#pragma once

class digital_output_pin
{
public:
    digital_output_pin(int pin_number);

    void set_high();
    void set_low();

    int get_pin_number() const;

private:
    int pin_number;
};