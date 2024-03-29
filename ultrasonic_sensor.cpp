#include "ultrasonic_sensor.hpp"

#ifndef PICO

namespace ardent
{
ultrasonic_sensor::ultrasonic_sensor(pin echo_pin, pin trigger_pin)
    : m_sr04(echo_pin.get_pin_number(), trigger_pin.get_pin_number())
{
}

centimeters ultrasonic_sensor::get_distance()
{
    const auto distance = centimeters{static_cast<decltype(centimeters::value)>(m_sr04.Distance())};
    return distance;
}
} // namespace ardent

#endif // ARDUINO