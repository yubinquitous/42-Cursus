#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <sstream>

class PmergeMe {

  public:
    PmergeMe();
    PmergeMe(PmergeMe const &src);
    ~PmergeMe();

    PmergeMe &operator=(PmergeMe const &rhs);

    void calculate(int argc, char *argv[]) const;

  private:
    void sort_list(std::list<int> &lst) const;
    void sort_deque(std::deque<int> &deq) const;

    void print_sorted_sequence(std::deque<int> &deq, std::list<int> &lst) const;

    bool isValidInput(std::string const &input) const;

    void print_sorting_time(long long const &time, int size, std::string const &type) const;
};

#endif /* ******************************************************** PMERGEME_H  \
        */