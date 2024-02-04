#include "ultrasonic_sensor.hpp"

namespace ardent
{
    ultrasonic_sensor::ultrasonic_sensor(pin echo_pin, pin trigger_pin)
        : m_sr04(echo_pin.get_pin_number(), trigger_pin.get_pin_number())
    {
    }

    std::optional<centimeters> ultrasonic_sensor::get_distance()
    {
        const auto distance = m_sr04.Distance();
        return distance >= ultrasonic_sensor::min_distance && distance <= ultrasonic_sensor::max_distance ? {distance} : {};
    }
}