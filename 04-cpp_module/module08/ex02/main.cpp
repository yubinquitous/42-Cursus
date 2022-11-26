#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main() {
    std::cout << "=========== TEST0 ===========" << std::endl;
    {
        MutantStack<int> mstack;
        std::list<int> lstack;

        mstack.push(5);
        lstack.push_back(5);
        mstack.push(17);
        lstack.push_back(17);

        std::cout << "mstack.top(): " << mstack.top() << std::endl;    // 17
        std::cout << "lstack.back(): " << lstack.back() << std::endl;  // 17

        mstack.pop();
        lstack.pop_back();

        std::cout << "mstack.size(): " << mstack.size() << std::endl;  // 1
        std::cout << "lstack.size(): " << lstack.size() << std::endl;  // 1

        mstack.push(3);
        lstack.push_back(3);
        mstack.push(5);
        lstack.push_back(5);
        mstack.push(737);
        lstack.push_back(737);
        mstack.push(0);
        lstack.push_back(0);

        MutantStack<int> mstack2(mstack);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        std::list<int>::iterator lit = lstack.begin();
        std::list<int>::iterator lite = lstack.end();
        MutantStack<int>::iterator it2 = mstack2.begin();
        MutantStack<int>::iterator ite2 = mstack2.end();

        // mstack : 0 737 5 3 5
        ++it;
        --it;
        std::cout << "mstack: ";
        while (it != ite) {
            std::cout << *it << " ";  // 5 3 5 737 0
            ++it;
        }
        std::cout << std::endl;
        std::cout << "lstack: ";
        while (lit != lite) {
            std::cout << *lit << " ";  // 5 3 5 737 0
            ++lit;
        }
        std::cout << std::endl;
        std::cout << "mstack2: ";
        while (it2 != ite2) {
            std::cout << *it2 << " ";  // 5 3 5 737 0
            ++it2;
        }
        std::cout << std::endl;
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

        // mstack: 0 737 5 3 5
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << " ";  // 0 737 5 3 5
            ++it;
        }
        std::cout << std::endl;
    }
    return 0;
}