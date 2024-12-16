#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
    private:
        T* _array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array& operator=(Array const& src);
        Array(Array const& copy);
        ~Array();

        T& operator[](unsigned int i);
        unsigned int size() const;
};

#include "Array.tpp"

#endif

