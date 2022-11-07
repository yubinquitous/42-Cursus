#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
   private:
    std::string _name;

   public:
    Zombie();
    Zombie(std::string name);

    void announce(void);

    ~Zombie();
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif