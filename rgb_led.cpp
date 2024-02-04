#include "rgb_led.hpp"

namespace ardent
{

rgb_led<common_cathode_tag>::rgb_led(pwm_pin red_pin, pwm_pin green_pin, pwm_pin blue_pin)
: m_red_pin(red_pin)
, m_green_pin(green_pin)
, m_blue_pin(blue_pin)
{}
        
void rgb_led<common_cathode_tag>::set_color(rgb color)
{
    m_red_pin.set_duty_cycle(color.red);
    m_green_pin.set_duty_cycle(color.green);
    m_blue_pin.set_duty_cycle(color.blue);  
}

void rgb_led<common_cathode_tag>::turn_on()
{
    m_red_pin.set_high();
    m_green_pin.set_high();
    m_blue_pin.set_high();
}

void rgb_led<common_cathode_tag>::turn_off()
{
    m_red_pin.set_low();
    m_green_pin.set_low();
    m_blue_pin.set_low();
}

}