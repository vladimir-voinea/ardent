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
// Specializations for converting between time units

// General template declaration
template <typename To, typename From>
To time_cast(From from);

// microseconds to other units
template <>
milliseconds time_cast<milliseconds, microseconds>(microseconds from) {
    return {from.value / 1000};
}

template <>
seconds time_cast<seconds, microseconds>(microseconds from) {
    return {from.value / 1000000};
}

template <>
minutes time_cast<minutes, microseconds>(microseconds from) {
    return {from.value / 60000000};
}

// milliseconds to other units
template <>
microseconds time_cast<microseconds, milliseconds>(milliseconds from) {
    return {from.value * 1000};
}

template <>
seconds time_cast<seconds, milliseconds>(milliseconds from) {
    return {from.value / 1000};
}

template <>
minutes time_cast<minutes, milliseconds>(milliseconds from) {
    return {from.value / 60000};
}

template <>
hours time_cast<hours, milliseconds>(milliseconds from) {
    return {from.value / 3600000};
}

// seconds to other units
template <>
microseconds time_cast<microseconds, seconds>(seconds from) {
    return {from.value * 1000000};
}

template <>
milliseconds time_cast<milliseconds, seconds>(seconds from) {
    return {from.value * 1000};
}

template <>
minutes time_cast<minutes, seconds>(seconds from) {
    return {from.value / 60};
}

template <>
hours time_cast<hours, seconds>(seconds from) {
    return {from.value / 3600};
}

// minutes to other units
template <>
microseconds time_cast<microseconds, minutes>(minutes from) {
    return {from.value * 60000000};
}

template <>
milliseconds time_cast<milliseconds, minutes>(minutes from) {
    return {from.value * 60000};
}

template <>
seconds time_cast<seconds, minutes>(minutes from) {
    return {from.value * 60};
}

template <>
hours time_cast<hours, minutes>(minutes from) {
    return {from.value / 60};
}


template <>
milliseconds time_cast<milliseconds, hours>(hours from) {
    return {from.value * 3600000};
}

template <>
seconds time_cast<seconds, hours>(hours from) {
    return {from.value * 3600};
}

template <>
minutes time_cast<minutes, hours>(hours from) {
    return {from.value * 60};
}

// Note: This set of specializations assumes that each 'value' field is of a type
// compatible with the conversion being performed (e.g., long long).

// You need to replace `// Add conversion logic here` with the actual conversion logic as shown in the examples.

} // namespace estd