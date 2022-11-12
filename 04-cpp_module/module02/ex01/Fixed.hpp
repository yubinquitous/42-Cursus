#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
   public:
    Fixed();
    Fixed(Fixed const& src);  // copy constructor
    Fixed(
        const int n);  // A constructor takes a constant integer as a parameter.
                       // It converts it to the corresponding fixed-point value.
    Fixed(const float n);  // A constructor takes a constant floating-point
                           // number as a parameter. It converts it to the
                           // corresponding fixed-point value.

    ~Fixed();

    Fixed& operator=(Fixed const& rhs);  // Copy assignation operator

    float toFloat(void) const;  // A member function that converts the
                                // fixed-point value to a floating-point number.
    int toInt(void) const;  // A member function that converts the fixed-point
                            // value to an integer value.

    int getRawBits(void) const;
    void setRawBits(int const raw);

   private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs);

#endif /* *********************************************************** FIXED_H \
        */