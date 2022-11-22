#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
   public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const& src);
    ShrubberyCreationForm(std::string const& target);

    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

    void execute(Bureaucrat const& executor) const;

   private:
    std::string _target;
};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H \
        */