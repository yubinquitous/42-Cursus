#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
   public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& src);
    ~FragTrap();

    FragTrap& operator=(FragTrap const& rhs);

    void highFivesGuys(void);

   private:
};

#endif /* ******************************************************** FRAGTRAP_H \
        */