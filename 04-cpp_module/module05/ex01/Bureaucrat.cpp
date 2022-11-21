#include "Bureaucrat.hpp"

#include <ios>

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()) {
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
    if (this != &rhs) {
        this->_grade = rhs.getGrade();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i) {
    o << i.getName() << ", bureaucrat grade: " << i.getGrade();
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::out_of_range Bureaucrat::GradeTooHighException() const {
    return std::out_of_range("Grade is too high");
}

std::out_of_range Bureaucrat::GradeTooLowException() const {
    return std::out_of_range("Grade is too low");
}

void Bureaucrat::incrementGrade() {
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << _name << " couldn't sign " << form.getName() << " because "
                  << e.what() << std::endl;
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

/* ************************************************************************** */