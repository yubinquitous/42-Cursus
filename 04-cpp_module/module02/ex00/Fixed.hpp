#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
   private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

   public:
    Fixed();                             // default constructor
    Fixed(const Fixed& src);             // copy constructor
    ~Fixed();                            // destructor
    Fixed& operator=(Fixed const& rhs);  // copy assignation operator

    int getRawBits(
        void) const;  // returns the raw value of the fixed point value
    void setRawBits(
        int const raw);  // sets the raw value of the fixed-point number
};

#endif /* ********************************************************* FIXED_H */