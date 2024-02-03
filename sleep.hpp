#pragma once

#include <time.hpp>

namespace ardent
{
    void sleep(estd::seconds duration);
    void sleep(estd::milliseconds duration);
    void sleep(estd::microseconds duration);
    estd::milliseconds millis();
    estd::microseconds micros();
}