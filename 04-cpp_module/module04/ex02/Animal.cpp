#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() { std::cout << "Animal constructor called" << std::endl; }

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
        this->type = rhs.type;
    }
    std::cout << "Animal assignation operator called" << std::endl;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType() const { return this->type; }

/* ************************************************************************** */