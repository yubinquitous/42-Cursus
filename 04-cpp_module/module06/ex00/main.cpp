#include "Conversion.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return 1;
    }

    Conversion c(argv[1]);
    c.printChar();
    c.printInt();
    c.printFloat();
    c.printDouble();

    return 0;
}