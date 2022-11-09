#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
   private:
    std::string _type;

   public:
    Weapon(std::string type);
    std::string& getType();
    void setType(std::string type);
    ~Weapon();
};

#endif