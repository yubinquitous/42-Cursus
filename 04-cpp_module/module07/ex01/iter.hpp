#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*f)(const T &)) {
    for (int i = 0; i < length; i++) f(array[i]);
}

template <typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

#endif