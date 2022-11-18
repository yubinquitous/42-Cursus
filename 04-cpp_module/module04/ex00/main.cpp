#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
    std::cout << "=========Animal TEST=========" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();  // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;

    std::cout << "=========Wrong Animal TEST=========" << std::endl;
    const WrongAnimal *j2 = new WrongCat();

    std::cout << j2->getType() << " " << std::endl;
    j2->makeSound();  // will output wrong animal sound!

    delete j2;

    return (0);
}