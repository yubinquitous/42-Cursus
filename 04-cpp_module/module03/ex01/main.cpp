#include "ScavTrap.hpp"

int main(void) {
    ScavTrap yubchoi("yubchoi");
    ScavTrap junkpark("junkpark");

    std::cout << "\n============ guardGate test ============" << std::endl;
    yubchoi.guardGate();

    std::cout << "\n============ attack test ============" << std::endl;
    yubchoi.attack("junkpark");
    junkpark.takeDamage(20);
    std::cout << std::endl;
}