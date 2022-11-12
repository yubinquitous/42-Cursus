#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
   public:
    Fixed();
    Fixed(Fixed const& src);
    Fixed(const int n);
    Fixed(const float n);

    ~Fixed();

    Fixed& operator=(Fixed const& rhs);

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);

    // comparison operators
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // arithmetic operators
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    // increment/decrement operators
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    // static member functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

   private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& i);

#endif /* *********************************************************** FIXED_H \
        */