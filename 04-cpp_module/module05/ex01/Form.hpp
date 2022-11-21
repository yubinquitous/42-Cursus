#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Form {
   public:
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(Form const& src);
    ~Form();
    Form& operator=(Form const& rhs);

    const std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat& bureaucrat);

    std::out_of_range GradeTooHighException() const;
    std::out_of_range GradeTooLowException() const;

   private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& o, Form const& i);

#endif /* ************************************************************ FORM_H \
        */