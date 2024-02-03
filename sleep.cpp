#include "sleep.hpp"
#include "Arduino.h"

namespace ardent
{
    void sleep(std::seconds duration)
    {
        sleep(std::time_cast<std::milliseconds>(duration));
    }

    void sleep(std::milliseconds duration)
    {
        delay(duration.value);
    }

    void sleep(std::microseconds duration)
    {
        delayMicroseconds(duration.value);
    }

    std::milliseconds millis()
    {
        return {::millis()};
    }

    std::microseconds micros()
    {
        return {::micros()};
    }
}