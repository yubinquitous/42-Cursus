#include "Zombie.hpp"

int main(void) {
    Zombie zombie("Foo");
    zombie.announce();

    Zombie *new_zombie = newZombie("Goo");
    new_zombie->announce();
    delete new_zombie;

    randomChump("Hoo");

    return 0;
}