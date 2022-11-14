#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap() {
    _name = "default";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
    std::cout << "ScavTrap" << _name << " Copy constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
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

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " is already dead!" << std::endl;
    } else if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!"
                  << std::endl;
        --_energyPoints;
    }
}

void ScavTrap::guardGate() {
    if (_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " is already dead!" << std::endl;
    } else if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " is now in Gate keeper mode"
                  << std::endl;
        --_energyPoints;
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */