#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <cmath>
#include <iostream>

class Conversion {
   public:
    Conversion();
    Conversion(const Conversion& src);
    Conversion(std::string const& str);
    ~Conversion();

    Conversion& operator=(const Conversion& rhs);

    void printChar();
    void printInt();
    void printFloat();
    void printDouble();

    std::runtime_error impossibleException();
    std::runtime_error nonDisplayableException();

   private:
    std::string _str;
    double _dvalue;
    bool _isChar();
    void _setPrecision();
};

#endif /* ****************************************************** CONVERSION_H \
        */