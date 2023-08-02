#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./bitcoin [file]" << std::endl;
        return 1;
    }

    BitcoinExchange bitcoinExchange;
    bitcoinExchange.loadDatabase("data.csv");
    bitcoinExchange.exchange(argv[1]);

    return 0;
}
