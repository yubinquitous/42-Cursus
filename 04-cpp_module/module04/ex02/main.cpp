#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    std::cout << "=========================================" << std::endl;
    // const Animal *meta = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "=========================================" << std::endl;
    Dog dog2;
    {
        Dog dog3 = dog2;
        dog3.makeSound();
    }
    std::cout << std::endl;

    system("leaks a.out | grep 'leaked bytes.'");
    return (0);
}