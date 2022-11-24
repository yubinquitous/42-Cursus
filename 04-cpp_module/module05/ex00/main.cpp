#include "Bureaucrat.hpp"

int main() {
    std::cout << "NormalTest" << std::endl;
    {
        Bureaucrat b("Normal", 75);
        std::cout << b;
        b.incrementGrade();
        std::cout << b;
        b.decrementGrade();
        std::cout << b;
    }
    std::cout << std::endl;

    std::cout << "TooHighTest" << std::endl;
    {
        Bureaucrat b("HIGH", 1);
        std::cout << b;
        try {
            b.incrementGrade();
            std::cout << b;
        } catch (std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "TooLowTest" << std::endl;
    {
        Bureaucrat b("LOW", 150);
        std::cout << b;
        try {
            b.decrementGrade();
            std::cout << b;
        } catch (std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    system("leaks a.out | grep 'total leaked bytes'");
    return 0;
}
