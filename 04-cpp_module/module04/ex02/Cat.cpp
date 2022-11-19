#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& src) {
    this->type = "Cat";
    this->brain = new Brain();
    *this = src;
    std::cout << "Cat copy constructor called" << std::endl;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat& Cat::operator=(Cat const& rhs) {
    if (this != &rhs) {
        this->type = rhs.getType();
        *this->brain = *rhs.brain;
    }
    std::cout << "Cat assignation operator called" << std::endl;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const { std::cout << "Yaong Yaong" << std::endl; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */