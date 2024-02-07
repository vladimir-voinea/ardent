#pragma once

#include <time.hpp>

namespace ardent
{
void sleep(ardent::seconds duration);
void sleep(ardent::milliseconds duration);
void sleep(ardent::microseconds duration);
ardent::milliseconds millis();
ardent::microseconds micros();
} // namespace ardent