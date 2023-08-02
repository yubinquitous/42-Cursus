#include "RPN.hpp"
#include <sstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() {}

RPN::RPN(const RPN &src) { *this = src; }

RPN::RPN(std::stack<double> number) : numbers(number) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN() {
    while (!this->numbers.empty()) {
        this->numbers.pop();
    }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &RPN::operator=(RPN const &rhs) {
    if (this != &rhs) {
        this->numbers = rhs.numbers;
    }
    return *this;
}

/*
** --------------------------------- METHODS
*----------------------------------
*/

void RPN::calculate(std::string input) {
    std::stack<double> numbers;
    std::stringstream ss(input);
    std::string token;
    double a, b;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (numbers.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            b = numbers.top();
            numbers.pop();
            a = numbers.top();
            numbers.pop();
            if (token == "+") {
                numbers.push(a + b);
            } else if (token == "-") {
                numbers.push(a - b);
            } else if (token == "*") {
                numbers.push(a * b);
            } else {
                numbers.push(a / b);
            }
        } else if (token.length() > 1 || !isdigit(token[0])) {
            std::cerr << "Error" << std::endl;
            return;
        } else {
            numbers.push(std::stod(token));
        }
    }
    if (numbers.size() != 1) {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << numbers.top() << std::endl;
}