#include "ultrasonic_sensor.hpp"

namespace ardent
{
    ultrasonic_sensor::ultrasonic_sensor(pin trig_pin, pin echo_pin)
        : m_sr04(trig_pin, echo_pin)
    {
    }

    centimeters ultrasonic_sensor::get_distance()
    {
        return centimeters{m_sr04.Distance()};
    }

    centimeters ultrasonic_sensor::get_distance_average(frequency freq, estd::milliseconds duration)
    {
        const auto wait_time = estl::milliseconds{1000 / freq.value};
        const auto samples = duration.value / wait_time;
        return get_distance_average(wait_time, samples);
    }

    centimeters ultrasonic_sensor::get_distance_average(estd::milliseconds delay, int samples)
    {
        return centimeters{m_sr04.DistanceAvg(delay.value, samples)};
    }
}