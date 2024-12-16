#include "Array.hpp"

template <typename T>
Array<T>::Array() {
    _array = NULL;
    _size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    _array = new T[n];
    _size = n;
}

template <typename T>
Array<T>::Array(Array const& copy) {
    _size = copy.size();
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _array[i] = copy._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& assign) {
    if (this != &assign) {
        delete[] _array;
        _size = assign.size();
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = assign._array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
    if (i >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}