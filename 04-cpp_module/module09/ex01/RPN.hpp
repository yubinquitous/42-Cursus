#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {

  public:
    RPN();
    RPN(RPN const &src);
    RPN(std::stack<double> number);

    ~RPN();

    RPN &operator=(RPN const &rhs);

    void calculate(std::string input);

  private:
    std::stack<double> numbers;
};

#endif /* ************************************************************* RPN_H  \
        */