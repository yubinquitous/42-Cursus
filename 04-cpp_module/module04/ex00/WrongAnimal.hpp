#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
   public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const& src);
    virtual ~WrongAnimal();

    WrongAnimal& operator=(WrongAnimal const& rhs);

    std::string getType() const;
    void makeSound() const;

   protected:
    std::string type;
};

#endif /* ***************************************************** WRONGANIMAL_H \
        */