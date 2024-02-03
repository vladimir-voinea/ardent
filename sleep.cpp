#include "sleep.hpp"
#include "Arduino.h"

namespace ardent
{
    void sleep(vl::seconds duration)
    {
        sleep(vl::time_cast<vl::milliseconds>(duration));
    }

    void sleep(vl::milliseconds duration)
    {
        delay(duration.value);
    }

    void sleep(vl::microseconds duration)
    {
        delayMicroseconds(duration.value);
    }

    vl::milliseconds millis()
    {
        return {::millis()};
    }

    vl::microseconds micros()
    {
        return {::micros()};
    }
}