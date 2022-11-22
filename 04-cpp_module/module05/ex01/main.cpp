#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    std::cout << "=====================Test=====================" << std::endl;
    {
        Bureaucrat bob("bob", 42);
        Form low("LOW", 150, 1);
        Form sign("SIGN", 42, 1);
        Form high("HIGH", 1, 1);

        std::cout << bob << std::endl;
        bob.signForm(low);
        bob.signForm(sign);
        bob.signForm(high);
    }
    system("leaks a.out | grep 'total leaked bytes'");
}