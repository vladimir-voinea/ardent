#pragma once

#include "time.hpp"

namespace ardent
{
    void sleep(std::seconds duration);
    void sleep(std::milliseconds duration);
    void sleep(std::microseconds duration);
    std::milliseconds millis();
    std::microseconds micros();
}