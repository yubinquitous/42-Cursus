#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() { _name = ""; }

Zombie::Zombie(std::string name) { _name = name; }

void Zombie::setName(std::string name) { _name = name; }

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() { std::cout << _name << " has been destroyed" << std::endl; }