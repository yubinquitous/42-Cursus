#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "Form.hpp"

class PresidentialPardonForm : public Form {
   public:
    PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const& src);
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

    void execute(Bureaucrat const& executor) const;

   private:
    std::string _target;
};

std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const& i);

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H \
        */