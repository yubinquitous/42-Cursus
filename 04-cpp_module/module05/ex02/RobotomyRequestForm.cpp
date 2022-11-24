#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
    : Form("RobotomyRequestForm", 72, 45), _target("default"){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : Form(src), _target(src._target) {
    *this = src;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("RobotomyRequestForm", 72, 45), _target(target) {}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& rhs) {
    if (this != &rhs) {
        this->_target = rhs._target;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw Form::FormNotSignedException();
    } else if (executor.getGrade() > this->getGradeToExecute()) {
        throw Form::GradeTooLowException();
    } else {
        std::cout << "Drilling noises..." << std::endl;
        if (std::rand() % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully"
                      << std::endl;
        else
            std::cout << "Robotomization failed" << std::endl;
    }
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* **************************************************************************
 */