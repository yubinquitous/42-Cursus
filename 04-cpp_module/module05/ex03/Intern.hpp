#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
   public:
    Intern();
    Intern(Intern const& src);
    ~Intern();

    Intern& operator=(Intern const& rhs);

    Form* makeForm(const std::string& formName, const std::string& target);
    Form* makePresidentialPardonForm(const std::string& target);
    Form* makeRobotomyRequestForm(const std::string& target);
    Form* makeShrubberyCreationForm(const std::string& target);

    std::runtime_error FormNotFoundException() const;

   private:
};

#endif /* ********************************************************** INTERN_H \
        */