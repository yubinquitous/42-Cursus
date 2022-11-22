#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
   public:
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(Form const& src);
    virtual ~Form();
    Form& operator=(Form const& rhs);

    const std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const& executor) const = 0;

    std::out_of_range GradeTooHighException() const;
    std::out_of_range GradeTooLowException() const;
    std::runtime_error FormNotSignedException() const;

   private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& o, Form const& i);

#endif /* ************************************************************ FORM_H \
        */