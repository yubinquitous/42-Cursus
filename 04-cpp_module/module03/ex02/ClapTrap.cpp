#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
    std::cout << "ClapTrap" << _name << " Copy constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
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

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    } else if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!"
                  << std::endl;
        --_energyPoints;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    } else if (_hitPoints > amount) {
        std::cout << "ClapTrap " << _name << " takes " << amount
                  << " points of damage!" << std::endl;
        _hitPoints -= amount;
    } else {
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
        _hitPoints = 0;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    } else if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is repaired by " << amount
                  << " points!" << std::endl;
        _hitPoints += amount;
        --_energyPoints;
    }
}

/*
** --------------------------------- ACCESSOR
*---------------------------------
*/

/* **************************************************************************
 */