#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
   private:
    T *_array;
    unsigned int _size;

   public:
    Array() : _array(new T[0]), _size(0) {}

    Array(unsigned int n) : _array(new T[n]), _size(n) {}

    Array(const Array &origin)
        : _array(new T[origin._size]), _size(origin._size) {
        for (unsigned int i = 0; i < _size; i++) _array[i] = origin._array[i];
    }

    Array &operator=(const Array &origin) {
        if (this != &origin) {
            delete[] _array;
            _array = new T[origin._size];
            _size = origin._size;
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = origin._array[i];
        }
        return *this;
    }

    ~Array() { delete[] _array; }

    T &operator[](unsigned int index) {
        if (index >= _size) throw std::out_of_range("index is out of bounds");
        return _array[index];
    }

    const T &operator[](unsigned int index) const {
        if (index >= _size) throw std::out_of_range("index is out of bounds");
        return _array[index];
    }

    unsigned int size() const { return _size; }
};

#endif