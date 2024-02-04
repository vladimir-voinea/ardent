#pragma once

#include "digital_output_pin.hpp"
#include "frequency.hpp"
#include <time.hpp>

namespace ardent
{
    class passive_buzzer
    {
    public:
        passive_buzzer(digital_output_pin pin);

        void beep(frequency freq, estd::milliseconds duration);

        void start_beeping(frequency freq);
        void stop_beeping();
    private:
        digital_output_pin m_pin;
    };
}
