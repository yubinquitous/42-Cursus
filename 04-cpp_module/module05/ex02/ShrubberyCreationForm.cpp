#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : Form(src), _target(src._target) {
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& rhs) {
    if (this != &rhs) {
        this->_target = rhs._target;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw Form::FormNotSignedException();
    } else if (executor.getGrade() > this->getGradeToExecute()) {
        throw Form::GradeTooLowException();
    } else {
        std::ofstream file(_target + "_shrubbery");
        if (file.is_open()) {
            // christmas tree ASCII code
            file << "      ." << std::endl;
            file << "   __/ \\__" << std::endl;
            file << "   \\     /" << std::endl;
            file << "   /.'o'.\\" << std::endl;
            file << "    .o.'." << std::endl;
            file << "   .'.'o'." << std::endl;
            file << "  o'.o.'.o." << std::endl;
            file << " .'.o.'.'.o." << std::endl;
            file << ".o.'.o.'.o.'." << std::endl;
            file << "   [_____]" << std::endl;
            file << "    \\___/ " << std::endl;
            file.close();
        } else
            std::cerr << "Error: unable to open file" << std::endl;
    }
}
/*
** --------------------------------- ACCESSOR
*---------------------------------
*/

/* **************************************************************************
 */