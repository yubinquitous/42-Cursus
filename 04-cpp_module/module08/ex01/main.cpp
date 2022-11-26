#include "Span.hpp"

int main(void) {
    std::cout << "============= TEST1 =============" << std::endl;
    {
        try {
            Span sp = Span(5);

            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "============= TEST2 =============" << std::endl;
    {
        try {
            std::vector<int> v(10000);
            for (int i = 0; i < 10000; i++) {
                v[i] = i;
            }
            Span sp = Span(10000);
            sp.addNumber(v.begin(), v.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;

            sp.addNumber(10000);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "============= TEST3 =============" << std::endl;
    {
        try {
            Span sp = Span(5);

            sp.addNumber(6);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << "This line should not be printed" << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    system("leaks a.out | grep 'leaked bytes'");
    return 0;
}