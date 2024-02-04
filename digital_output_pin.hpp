#pragma once

namespace ardent
{
 
class digital_output_pin
{
public:
    digital_output_pin(int pin_number);

    void set_high();
    void set_low();

private:
    int pin_number;
};

}