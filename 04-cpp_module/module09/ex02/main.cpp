#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "usage: ./pmergeme [... int]" << std::endl;
        return 1;
    }

    PmergeMe pmerge;
    pmerge.calculate(argc, argv);

    return 0;
}