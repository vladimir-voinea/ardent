#pragma once

#ifndef PICO

#include "detail/HC-SR04/SR04.h"
#include "distance.hpp"
#include "pin.hpp"
#include <optional>
#include <time.hpp>

namespace ardent
{
/*
    Max frequency is 40hz
    Min reliable measurement: 2cm
    Max reliable measurement: 400cm
    Error: +/- 3mm
*/
class ultrasonic_sensor
{
  public:
    static constexpr centimeters min_distance = centimeters{2};
    static constexpr centimeters max_distance = centimeters{400};
    static constexpr millimeters error = millimeters{3};

  public:
    ultrasonic_sensor(pin echo_pin, pin trigger_pin);
    centimeters get_distance();

  private:
    SR04 m_sr04;
};
} // namespace ardent

#endif // ARDUINO
