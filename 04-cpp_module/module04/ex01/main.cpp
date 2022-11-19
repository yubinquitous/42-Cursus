#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    std::cout << "=========================================" << std::endl;
    Animal *animal[4] = {new Dog(), new Cat(), new Dog(), new Cat()};
    for (int i = 0; i < 4; i++) {
        animal[i]->makeSound();
    }
    for (int i = 0; i < 4; i++) {
        delete animal[i];
    }

    std::cout << "=========================================" << std::endl;
    Dog dog2;
    {
        Dog dog3 = dog2;
        dog3.makeSound();
    }
    std::cout << std::endl;

    system("leaks a.out | grep 'leaked bytes.'");
}