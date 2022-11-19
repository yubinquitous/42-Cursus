#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class Bureaucrat {
   public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);

    Bureaucrat(Bureaucrat const& src);
    ~Bureaucrat();

    Bureaucrat& operator=(Bureaucrat const& rhs);

    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    std::runtime_error GradeTooHighException();
    std::runtime_error GradeTooLowException();

   private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i);

#endif /* ****************************************************** BUREAUCRAT_H \
        */