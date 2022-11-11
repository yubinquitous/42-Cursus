#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
   public:
    Fixed();
    Fixed(Fixed const& src);
    ~Fixed();

    Fixed& operator=(Fixed const& rhs);

   private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
};

#endif /* *********************************************************** FIXED_H \
        */