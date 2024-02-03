#include "sleep.hpp"
#include "Arduino.h"

namespace ardent
{
    void sleep(estd::seconds duration)
    {
        sleep(estd::time_cast<estd::milliseconds>(duration));
    }

    void sleep(estd::milliseconds duration)
    {
        delay(duration.value);
    }

    void sleep(estd::microseconds duration)
    {
        delayMicroseconds(duration.value);
    }

    estd::milliseconds millis()
    {
        return {::millis()};
    }

    estd::microseconds micros()
    {
        return {::micros()};
    }
}