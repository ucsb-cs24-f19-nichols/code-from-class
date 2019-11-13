#include "max.h"

// max.cpp compiled by itself will not make any code,
// because the function is never parameterized by a certain type

// solution: #include "max.cpp" INSIDE max.h

template <class T>
T maximum1(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}