#pragma once

#include "detail/HC-SR04/SR04.h"
#include "pin.hpp"
#include "distance.hpp"
#include <time.hpp>

namespace ardent
{
    class ultrasonic_sensor
    {
    public:
        ultrasonic_sensor(pin trig_pin, pin echo_pin);
        centimeters get_distance();
        centimeters get_distance_average(frequency freq, estd::milliseconds duration);
        centimeters get_distance_average(estd::milliseconds delay, int samples);
    private:
        SR04 m_sr04;
    };
}