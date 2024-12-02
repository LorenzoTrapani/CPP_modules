#ifndef WHATEVER_HPP
#define WHATERVER_HPP

#include <iostream>
#include <string>
#include <cmath>

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T const &a, T const &b)
{
    return (a < b) ? a : b;
}

template <typename T>
T max(T const &a, T const &b)
{
    return (a > b) ? a : b;
}

#endif