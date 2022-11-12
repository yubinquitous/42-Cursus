#include "Fixed.hpp"

#include <cmath>  // roundf

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
    : _fixedPointValue(roundf(n * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed& Fixed::operator=(Fixed const& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    _fixedPointValue = rhs.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
    o << rhs.toFloat();
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const { return _fixedPointValue >> _fractionalBits; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const { return _fixedPointValue; }

void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

/* ************************************************************************** */