#pragma once

#include "digital_output_pin.hpp"
#include "frequency.hpp"
#include "i_loop_observer.hpp"
#include <functional>
#include <optional>
#include <sleep.hpp>
#include <time.hpp>
#include <tuple>

namespace ardent
{
class passive_buzzer : public i_loop_observer
{
  public:
    passive_buzzer(digital_output_pin pin);

    void beep(frequency freq, estd::milliseconds duration, std::function<void(void)> callback);
    void mute(estd::milliseconds duration, std::function<void(void)> callback);
    void mute();
    void unmute();

    void update() override;
    bool is_beeping() const;
    bool is_muted() const;

    void start_beeping(frequency freq);
    void stop_beeping();

  private:
    digital_output_pin m_pin;
    using current_beep_info = std::tuple<estd::milliseconds, estd::milliseconds>;
    current_beep_info m_current_beep = {{0}, {0}};
    current_beep_info m_current_mute = {{0}, {0}};
    std::function<void(void)> m_callback;
};
} // namespace ardent
