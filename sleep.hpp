#pragma once

#include "time.hpp"

namespace ardent
{
    void sleep(vl::seconds duration);
    void sleep(vl::milliseconds duration);
    void sleep(vl::microseconds duration);
    vl::milliseconds millis();
    vl::microseconds micros();
}