#include <iostream>

#include "Fixed.hpp"

int main(void) {
    Fixed a;     // default constructor
    Fixed b(a);  // Copy constructor
    Fixed c;

    c = b;  // Copy assignation operator called

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}