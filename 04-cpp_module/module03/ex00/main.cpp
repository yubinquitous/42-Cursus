#include "ClapTrap.hpp"

int main(void) {
    ClapTrap yubchoi("yubchoi");
    ClapTrap mher("mher");
    ClapTrap junkpark("junkpark");
    ClapTrap donshin("donshin");

    std::cout << "\n============ attack test ============" << std::endl;
    for (int i = 0; i < 10; i++) {
        yubchoi.attack("mher");
    }
    yubchoi.attack("mher");
    yubchoi.beRepaired(10);

    std::cout << "\n============ takeDamage test ============" << std::endl;
    mher.takeDamage(10);
    mher.attack("junkpark");
    mher.beRepaired(10);

    std::cout << "\n============ repair test ============" << std::endl;
    donshin.takeDamage(9);
    donshin.beRepaired(1);
    donshin.takeDamage(10);
    donshin.takeDamage(1);

    std::cout << std::endl;

    return 0;
}