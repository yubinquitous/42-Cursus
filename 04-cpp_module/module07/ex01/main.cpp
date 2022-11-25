#include "iter.hpp"

int main(void) {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string stringArray[] = {"Hello", "World", "!"};

    iter(intArray, 5, print);
    iter(stringArray, 3, print);

    return 0;
}