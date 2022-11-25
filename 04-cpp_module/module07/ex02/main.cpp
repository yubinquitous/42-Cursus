#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char **) {
    std::cout << "================== TEST #1 ==================" << std::endl;
    {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++) {
            a[i] = i;
        }
        Array<int> b(a);
        b[0] = 42;
        for (unsigned int i = 0; i < b.size(); i++) {
            std::cout << "a[" << i << "]: " << a[i] << "\t\t";
            std::cout << "b[" << i << "]: " << b[i] << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "================== TEST #2 ==================" << std::endl;
    {
        Array<char> a(5);
        for (unsigned int i = 0; i < a.size(); i++) {
            a[i] = i + 65;
        }
        Array<char> b(10);
        for (unsigned int i = 0; i < b.size(); i++) {
            b[i] = i + 97;
        }
        std::cout << "BEFORE ASSIGNATION" << std::endl;
        for (unsigned int i = 0; i < b.size(); i++) {
            std::cout << "a[" << i << "]: ";
            if (i < a.size())
                std::cout << a[i] << "\t\t";
            else
                std::cout << " "
                          << "\t\t";
            std::cout << "b[" << i << "]: " << b[i] << std::endl;
        }
        b = a;
        std::cout << "AFTER ASSIGNATION" << std::endl;
        for (unsigned int i = 0; i < b.size(); i++) {
            std::cout << "a[" << i << "]: " << a[i] << "\t\t";
            std::cout << "b[" << i << "]: " << b[i] << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "================== TEST #3 ==================" << std::endl;
    {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++) {
            a[i] = i;
        }
        try {
            std::cout << a[5] << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << system("leaks a.out | grep 'total leaked bytes'");
    return 0;
}