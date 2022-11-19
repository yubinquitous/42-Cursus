#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : _type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& src) {
    *this = src;
    std::cout << "Animal copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal& Animal::operator=(Animal const& rhs) {
    if (this != &rhs) {
        this->_type = rhs._type;
    }
    std::cout << "Animal assignation operator called" << std::endl;
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