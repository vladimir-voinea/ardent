#pragma once

#include "i_led.hpp"
#include "pwm_pin.hpp"
#include <color.hpp>

namespace ardent
{
struct common_cathode_tag
{
};
struct common_anode_tag
{
};

template <typename TType> class rgb_led final : public i_led
{
  public:
    void set_color(rgb color);
    void turn_on() override;
    void turn_off() override;
};

template <> class rgb_led<common_cathode_tag> final : public i_led
{
  public:
    rgb_led(pwm_pin red_pin, pwm_pin green_pin, pwm_pin blue_pin);

    void set_color(rgb color);
    void turn_on() override;
    void turn_off() override;

  private:
    pwm_pin m_red_pin;
    pwm_pin m_green_pin;
    pwm_pin m_blue_pin;
};
} // namespace ardent