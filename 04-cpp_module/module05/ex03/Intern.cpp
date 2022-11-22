#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {}

Intern::Intern(const Intern& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern& Intern::operator=(Intern const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Form* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formNames[3] = {"presidential pardon", "robotomy request",
                                      "shrubbery creation"};
    Form* (Intern::*formFunctions[3])(const std::string& target) = {
        &Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm,
        &Intern::makeShrubberyCreationForm};
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formFunctions[i])(target);
        }
    }
    throw FormNotFoundException();
}

Form* Intern::makePresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Form* Intern::makeRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

Form* Intern::makeShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

std::runtime_error Intern::FormNotFoundException() const {
    return std::runtime_error("Form not found");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* **************************************************************************
 */