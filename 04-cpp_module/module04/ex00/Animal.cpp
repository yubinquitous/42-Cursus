#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : _type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal& Animal::operator=(Animal const& rhs) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &rhs) {
        this->_type = rhs._type;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType() const { return this->_type; }

/* ************************************************************************** */