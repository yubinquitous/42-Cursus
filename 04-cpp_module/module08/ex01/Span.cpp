#include "Span.hpp"

#include <stdexcept>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _n(0), _v() {}

Span::Span(const Span& src) : _n(src._n), _v(src._v) { *this = src; }

Span::Span(unsigned int n) : _n(n), _v() {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span& Span::operator=(Span const& rhs) {
    if (this != &rhs) {
        this->_v = rhs._v;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(unsigned int n) {
    if (_v.size() < _n) {
        _v.push_back(n);
    } else {
        throw std::runtime_error("Span is full");
    }
}

void Span::addNumber(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end) {
    if (_v.size() + (end - begin) <= _n) {
        _v.insert(_v.end(), begin, end);
    } else {
        throw std::runtime_error("Span is full");
    }
}

unsigned int Span::shortestSpan() {
    if (_v.size() < 2) {
        throw std::runtime_error("Not enough numbers");
    }
    std::sort(_v.begin(), _v.end());
    int min = _v[1] - _v[0];
    for (unsigned int i = 1; i < _v.size() - 1; i++) {
        min = std::min(min, _v[i + 1] - _v[i]);
    }
    return min;
}

unsigned int Span::longestSpan() {
    if (_v.size() < 2) {
        throw std::runtime_error("Not enough numbers");
    }
    std::sort(_v.begin(), _v.end());
    return _v[_v.size() - 1] - _v[0];
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */