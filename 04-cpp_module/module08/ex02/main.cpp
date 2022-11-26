#include <iostream>

#include "MutantStack.hpp"

int main() {
    std::cout << "=========== TEST0 ===========" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;  // 17

        mstack.pop();

        std::cout << mstack.size() << std::endl;  // 1

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;  // 5 3 5 737 0
            ++it;
        }
    }
    std::cout << std::endl;

    std::cout << "=========== TEST1 ===========" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;  // 17

        mstack.pop();

        std::cout << mstack.size() << std::endl;  // 1

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::reverse_iterator it = mstack.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack.rend();

        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;  // 0 737 5 3 5
            ++it;
        }
    }

    std::cout << "=========== TEST2 ===========" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;  // 17

        mstack.pop();

        std::cout << mstack.size() << std::endl;  // 1

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int> mstack2(mstack);

        MutantStack<int>::iterator it = mstack2.begin();
        MutantStack<int>::iterator ite = mstack2.end();

        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;  // 5 3 5 737 0
            ++it;
        }
    }
    return 0;
}