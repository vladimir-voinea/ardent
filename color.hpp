#pragma once

#include <stdint.h>

namespace ardent
{
    struct rgb
    {
        using value_type = uint8_t;

        value_type red;
        value_type green;
        value_type blue;
    };
}