#pragma once

#include <type_traits>

namespace ardent
{
struct meters
{
    int value;
};

struct centimeters
{
    int value;
};

struct millimeters
{
    int value;
};

template <typename From, typename To> To distance_cast(From from)
{
    if constexpr (std::is_same_v<From, meters> && std::is_same_v<To, centimeters>)
    {
        return To{from.value * 100};
    }
    else if constexpr (std::is_same_v<From, meters> && std::is_same_v<To, millimeters>)
    {
        return To{from.value * 1000};
    }
    else if constexpr (std::is_same_v<From, centimeters> && std::is_same_v<To, meters>)
    {
        return To{from.value / 100};
    }
    else if constexpr (std::is_same_v<From, centimeters> && std::is_same_v<To, millimeters>)
    {
        return To{from.value * 10};
    }
    else if constexpr (std::is_same_v<From, millimeters> && std::is_same_v<To, meters>)
    {
        return To{from.value / 1000};
    }
    else if constexpr (std::is_same_v<From, millimeters> && std::is_same_v<To, centimeters>)
    {
        return To{from.value / 10};
    }
    return To{};
}
} // namespace ardent