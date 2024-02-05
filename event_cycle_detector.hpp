#pragma once

#include "debounce.hpp"
#include <Arduino.h>
#include <functional>
#include <optional>
#include <type_traits>

namespace ardent
{

template <typename TInputType, typename TCallback> class event_cycle_detector
{
  public:
    event_cycle_detector(TInputType &&input, TCallback &&onCompleteCallback,
                         estd::milliseconds debounceTime = estd::milliseconds{50})
        : m_debounce(
              std::forward<TInputType>(input), [this](auto newState) { this->onDebouncedStateChange(newState); },
              debounceTime),
          m_onCompleteCallback(std::forward<TCallback>(onCompleteCallback))
    {
    }

    void update()
    {
        if (!m_initialState)
        {
            auto initialState = m_debounce.get_input().read();
            m_initialState = initialState;
            m_lastDebouncedState = initialState;
            m_lastState = initialState;
            return;
        }

        m_debounce.update();
    }

  private:
    debounce<TInputType, std::function<void(typename TInputType::reading_type)>> m_debounce;
    TCallback m_onCompleteCallback;
    std::optional<typename TInputType::reading_type> m_initialState;
    typename TInputType::reading_type m_lastDebouncedState;
    typename TInputType::reading_type m_lastState;

    void onDebouncedStateChange(typename TInputType::reading_type newState)
    {
        if (!m_initialState)
        {
            return;
        }

        if (newState != m_lastDebouncedState)
        {
            if (newState == *m_initialState && m_lastDebouncedState != *m_initialState)
            {
                m_onCompleteCallback();
            }
            m_lastDebouncedState = newState;
        }
    }
};

} // namespace ardent
