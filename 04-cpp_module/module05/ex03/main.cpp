#include "Intern.hpp"

int main() {
    std::cout << "-----Test#1 Intern::makeForm(): Success-----" << std::endl;
    {
        try {
            Intern intern;
            Form* scf;
            Form* rrf;
            Form* ppf;

            scf = intern.makeForm("shrubbery creation", "yubchoi");
            rrf = intern.makeForm("robotomy request", "junkpark");
            ppf = intern.makeForm("presidential pardon", "mher");

            std::cout << *scf << std::endl;
            std::cout << *rrf << std::endl;
            std::cout << *ppf << std::endl;

            delete scf;
            delete rrf;
            delete ppf;
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "-----Test#2 Intern::makeForm(): Failure-----" << std::endl;
    {
        try {
            Intern intern;
            Form* nonExistentForm;

            nonExistentForm = intern.makeForm("nonExistentForm", "name");
            std::cout << nonExistentForm << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    system("leaks a.out | grep 'total leaked bytes'");
    return 0;
}