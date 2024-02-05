#pragma once

#include <time.hpp>
#include <sleep.hpp>
#include <Arduino.h>

namespace ardent
{

// Assuming existence of necessary includes for ardent::millis and estd::milliseconds

template<typename TInputType, typename TCallback>
class debounce {
public:
    debounce(TInputType&& input, TCallback&& callback, estd::milliseconds debounceTime = estd::milliseconds{50})
    : m_input(std::forward<TInputType>(input)),
      m_callback(std::forward<TCallback>(callback)),
      m_debounceTime(debounceTime),
      m_lastState(input.read()), // Assuming TInputType has a read() method returning a bool
      m_lastDebounceTime({0})
    {}

    void update()
    {
      const auto now = ardent::millis();
      const auto currentState = m_input.read();

      if(now.value - m_lastDebounceTime.value > m_debounceTime.value)
      {
        if(currentState != m_lastState)
        {
          m_lastState = currentState;
          m_lastDebounceTime = now;
          m_callback(currentState);
        }
      }
    }

    TInputType& get_input()
    {
      return m_input;
    }

private:
    TInputType m_input;
    TCallback m_callback;
    estd::milliseconds m_debounceTime;
    typename TInputType::reading_type m_lastState;
    estd::milliseconds m_lastDebounceTime;
    typename TInputType::reading_type m_lastDebouncedState = m_lastState;
};


}