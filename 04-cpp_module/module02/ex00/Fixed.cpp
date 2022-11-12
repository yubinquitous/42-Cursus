#include "Fixed.hpp"

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

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed& Fixed::operator=(Fixed const& rhs) {
    std::cout << "Copy assignation operator called" << std::endl;
    _fixedPointValue = rhs.getRawBits();

    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

/* ************************************************************************** */