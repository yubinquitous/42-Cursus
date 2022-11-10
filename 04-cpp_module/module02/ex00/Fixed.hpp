#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
   private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

   public:
    Fixed();                             // default constructor
    Fixed(Fixed const& obj);             // copy constructor
    ~Fixed();                            // destructor
    Fixed& operator=(Fixed const& obj);  // assignation operator

    int getRawBits(
        void) const;  // returns the raw value of the fixed point value
    void setRawBits(
        int const raw);  // sets the raw value of the fixed-point number
};

#endif /* ********************************************************* FIXED_H */