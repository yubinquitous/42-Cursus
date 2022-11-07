#include "Zombie.hpp"

int main(void) {
    // 생성자
    Zombie yubchoi_zombie;
    yubchoi_zombie.announce();

    //  생성자 오버로딩
    Zombie foo_zombie("Foo");
    foo_zombie.announce();

    //  동적할당
    Zombie *new_zombie = newZombie("Goo");
    new_zombie->announce();
    delete new_zombie;

    // 정적할당
    randomChump("Hoo");

    return 0;
}