#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
   private:
    std::string _name;

   public:
    Zombie();
    Zombie(std::string name);

    void setName(std::string name);
    void announce(void);

    ~Zombie(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif