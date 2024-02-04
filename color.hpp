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

    namespace color
    {
        constexpr rgb red{255, 0, 0};
        constexpr rgb green{0, 255, 0};
        constexpr rgb blue{0, 0, 255};
        constexpr rgb yellow{255, 255, 0};
        constexpr rgb white{255, 255, 255};
    }
}