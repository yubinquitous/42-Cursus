#include "Bureaucrat.hpp"
#include "Form.hpp"

void test_form(std::string name, bool sign, int grade) {
    try {
        Form form = Form(name, sign, grade);
        std::cout << form << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

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
}