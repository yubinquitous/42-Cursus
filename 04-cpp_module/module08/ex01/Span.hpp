#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Span {
   public:
    Span();
    Span(const Span& src);
    ~Span();
    Span& operator=(const Span& rhs);

    Span(unsigned int n);
    void addNumber(unsigned int n);
    void addNumber(std::vector<int>::iterator begin,
                   std::vector<int>::iterator end);
    unsigned int shortestSpan();
    unsigned int longestSpan();

   private:
    const unsigned int _n;
    std::vector<int> _v;
};

#endif /* ************************************************************ SPAN_H \
        */