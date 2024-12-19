#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Len, typename F>
void iter(T *array, Len length, F func)
{
    for (Len i = 0; i < length; ++i)
        func(array[i]);
}

#endif