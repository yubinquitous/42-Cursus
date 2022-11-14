#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
   public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& src);
    ~ClapTrap();

    ClapTrap& operator=(const ClapTrap& rhs);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

   private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

#endif /* ******************************************************** CLAPTRAP_H \
        */