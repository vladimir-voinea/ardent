#pragma once

#include "digital_output_pin.hpp"
#include "frequency.hpp"
#include "i_loop_observer.hpp"
#include <sleep.hpp>
#include <time.hpp>
#include <utility>

namespace ardent
{
    class passive_buzzer : public i_loop_observer
    {
    public:
        passive_buzzer(digital_output_pin pin);

        void beep(frequency freq, estd::milliseconds duration);

        void update() override;
        bool is_beeping() const { return m_current_beep.has_value(); }

        void start_beeping(frequency freq);
        void stop_beeping();
    private:
        digital_output_pin m_pin;
        using current_beep_info = std::tuple<estd::milliseconds, estd::milliseconds>;
        std::optional<current_beep_info> m_current_beep;
    };
}
