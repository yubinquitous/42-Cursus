#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
   public:
    PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const& src);
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

    void execute(const Bureaucrat& executor) const;

   private:
    std::string _target;
};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H \
        */