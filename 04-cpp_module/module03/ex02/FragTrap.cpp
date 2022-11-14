#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap() {
    _name = "default";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
    std::cout << "FragTrap" << _name << " Copy constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
    if (this != &rhs) {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys(void) {
    if (_hitPoints == 0) {
        std::cout << "FragTrap " << _name << " is already dead!" << std::endl;
    } else if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name << " is out of energy!" << std::endl;
    } else {
        std::cout << "FragTrap " << _name << " gives a high five!" << std::endl;
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */