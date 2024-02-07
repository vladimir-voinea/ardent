#include "sleep.hpp"
#include "Arduino.h"

namespace ardent
{
void sleep(ardent::seconds duration)
{
    sleep(estd::time_cast<ardent::milliseconds>(duration));
}

void sleep(ardent::milliseconds duration)
{
    ::delay(duration.value);
}

void sleep(ardent::microseconds duration)
{
    ::delayMicroseconds(duration.value);
}

ardent::milliseconds millis()
{
    return {::millis()};
}

ardent::microseconds micros()
{
    return {::micros()};
}
} // namespace ardent