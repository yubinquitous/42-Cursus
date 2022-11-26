#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*f)(T &)) {
    for (int i = 0; i < length; i++) f(array[i]);
}

template <typename T>
void print(T &x) {
    std::cout << x << std::endl;
}

template <typename T>
void addOne(T &x) {
    x++;
}

#endif