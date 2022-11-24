#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
    : _name("default"),
      _isSigned(false),
      _gradeToSign(150),
      _gradeToExecute(150) {}

Form::Form(const Form& src)
    : _name(src._name),
      _isSigned(src._isSigned),
      _gradeToSign(src._gradeToSign),
      _gradeToExecute(src._gradeToExecute) {}

Form::Form(const std::string& name, const int gradeToSign,
           const int gradeToExecute)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form& Form::operator=(Form const& rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, Form const& i) {
    o << i.getName() << ", form grade to sign: " << i.getGradeToSign()
      << ", form grade to execute: " << i.getGradeToExecute()
      << ", form is signed: " << std::boolalpha << i.getSigned();
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw Form::GradeTooLowException();
    } else {
        this->_isSigned = true;
    }
}

std::out_of_range Form::GradeTooHighException() const {
    return std::out_of_range("Grade is too high");
}

std::out_of_range Form::GradeTooLowException() const {
    return std::out_of_range("Grade is too low");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string Form::getName() const { return this->_name; }

bool Form::getSigned() const { return this->_isSigned; }

int Form::getGradeToSign() const { return this->_gradeToSign; }

int Form::getGradeToExecute() const { return this->_gradeToExecute; }

/* **************************************************************************
 */