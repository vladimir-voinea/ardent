#pragma once

namespace ardent
{
    class i_led
    {
    public:
        virtual ~i_led() = default;
        virtual void turn_on() = 0;
        virtual void turn_off() = 0;
    };
}