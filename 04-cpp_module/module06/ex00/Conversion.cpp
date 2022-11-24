#include "Conversion.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Conversion::Conversion() : _str(NULL), _dvalue(0.0) {}

Conversion::Conversion(const Conversion& src)
    : _str(src._str), _dvalue(src._dvalue) {
    *this = src;
}

Conversion::Conversion(const std::string& str) : _str(str) {
    _dvalue = std::atof(_str.c_str());
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Conversion::~Conversion() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Conversion& Conversion::operator=(const Conversion& rhs) {
    if (this != &rhs) {
        this->_str = rhs._str;
        this->_dvalue = rhs._dvalue;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool Conversion::_isChar() {
    return (_str.length() == 1 && !std::isdigit(_str[0]));
}

void Conversion::_setPrecision() {
    std::cout.precision(1);
    std::cout << std::fixed;
}

void Conversion::printChar() {
    std::cout << "char : ";

    if (_isChar()) {
        std::cout << "'" << static_cast<char>(_str[0]) << "'" << std::endl;
    } else {
        try {
            if (_dvalue < CHAR_MIN || _dvalue > CHAR_MAX || std::isnan(_dvalue))
                throw impossibleException();
            else if (!std::isprint(static_cast<char>(_dvalue)))
                throw nonDisplayableException();
            else
                std::cout << "'" << static_cast<char>(_dvalue) << "'"
                          << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void Conversion::printInt() {
    std::cout << "Int : ";

    if (_isChar()) {
        std::cout << static_cast<int>(_str[0]) << std::endl;
    } else {
        try {
            if (_dvalue < INT_MIN || _dvalue > INT_MAX || std::isnan(_dvalue))
                throw impossibleException();
            else
                std::cout << static_cast<int>(_dvalue) << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void Conversion::printFloat() {
    std::cout << "float : ";

    _setPrecision();

    if (_isChar()) {
        std::cout << static_cast<float>(_str[0]) << "f" << std::endl;
    } else {
        try {
            if (isinf(static_cast<float>(_dvalue)) && !isinf(_dvalue))
                throw impossibleException();
            else {
                std::cout << static_cast<float>(_dvalue) << "f" << std::endl;
            }
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void Conversion::printDouble() {
    std::cout << "double: ";

    _setPrecision();
    std::cout << _dvalue << std::endl;
}

std::runtime_error Conversion::impossibleException() {
    return std::runtime_error("impossible");
}

std::runtime_error Conversion::nonDisplayableException() {
    return std::runtime_error("Non displayable");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */