#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() {
    this->_type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) {
    *this = src;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat& WrongCat::operator=(WrongCat const& rhs) {
    if (this != &rhs) {
        this->_type = rhs.getType();
    }
    std::cout << "WrongCat assignation operator called" << std::endl;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound() const { std::cout << "Bark Bark" << std::endl; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */