#pragma once

namespace ardent
{

class pin
{
public:
    pin(int pin_number);

    int get_pin_number() const;

protected:
    int pin_number;
};

}