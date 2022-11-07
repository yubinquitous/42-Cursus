#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() { _name = "yubchoi"; }

Zombie::Zombie(std::string name) { _name = name; }

Zombie::~Zombie() { std::cout << _name << " has been destroyed" << std::endl; }

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}