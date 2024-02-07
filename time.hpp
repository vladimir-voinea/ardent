#pragma once

#include <stddef.h>
#include <type_traits>

namespace estd
{

struct microseconds
{
    long unsigned int value;
};

struct milliseconds
{
    long unsigned int value;
};

struct seconds
{
    long unsigned int value;
};

struct minutes
{
    long unsigned int value;
};

struct hours
{
    long unsigned int value;
};

template <typename To, typename From> To time_cast(From from);

} // namespace estd