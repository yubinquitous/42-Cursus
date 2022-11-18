#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {
    for (int i = 0; i < 100; i++) this->_ideas[i] = "default";
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& src) {
    *this = src;
    std::cout << "Brain copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain& Brain::operator=(Brain const& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) this->_ideas[i] = rhs._ideas[i];
    }
    std::cout << "Brain assignation operator called" << std::endl;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */