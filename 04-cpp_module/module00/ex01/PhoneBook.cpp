#include "PhoneBook.hpp"

#include <stdlib.h>

#include <iomanip>  // std::setw

PhoneBook::PhoneBook() { _idx = 0; }

PhoneBook::~PhoneBook() {}

bool PhoneBook::_readLine(std::string msg, std::string &str,
                          std::string constraint) {
    std::string line;

    std::cout << msg;

    std::getline(std::cin, line);
    if (std::cin.fail()) {
        std::cout << std::endl;
        exit(1);
    }
    if (line.length() == 0 ||
        line.find_first_not_of(constraint) != std::string::npos) {
        return (false);
    }
    str = line;
    return (true);
}

std::string _shorten(std::string str) {
    if (str.length() > 10) {
        str = str.substr(0, 9);
        str.append(".");
    }
    return (str);
}

void PhoneBook::_add() {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string secret;
    std::string constraint =
        "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int idx = _idx % 8;

    if (_readLine("Enter First Name: ", firstName, constraint) &&
        _readLine("Enter Last Name: ", lastName, constraint) &&
        _readLine("Enter Nickname: ", nickname, constraint) &&
        _readLine("Enter Phone Number: ", phoneNumber, constraint) &&
        _readLine("Enter Darkest Secret: ", secret, constraint)) {
        _contacts[idx].set_first_name(firstName);
        _contacts[idx].set_last_name(lastName);
        _contacts[idx].set_nickname(nickname);
        _contacts[idx].set_phone_number(phoneNumber);
        _contacts[idx].set_secret(secret);
        _idx = (_idx + 1) % 8;
    } else {
        std::cout << "Invalid input" << std::endl;
    }
}

void PhoneBook::_search() {
    int idx = _idx % 8;
    int i = 0;
    int j = 0;
    int k = 0;
    int num = 0;
    std::string line;

    std::cout << "     index|first name| last name| nickname|" << std::endl;
    for (i = 0; i < idx; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << _shorten(_contacts[i].get_first_name())
                  << "|";
        std::cout << std::setw(10) << _shorten(_contacts[i].get_last_name())
                  << "|";
        std::cout << std::setw(10) << _shorten(_contacts[i].get_nickname())
                  << "|";
        std::cout << std::endl;
    }

    _readLine("Enter index: ", line, "0123456789");
    num = line[0] - '0';
    if (num < 0 || num > 7) {
        std::cout << "Error: Invalid input" << std::endl;
        return;
    }
    std::cout << "First Name: " << _contacts[num].get_first_name() << std::endl;
    std::cout << "Last Name: " << _contacts[num].get_last_name() << std::endl;
    std::cout << "Nickname: " << _contacts[num].get_nickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[num].get_phone_number()
              << std::endl;
    std::cout << "Darkest Secret: " << _contacts[num].get_secret() << std::endl;
}

void PhoneBook::run() {
    std::string line;

    while (1) {
        _readLine("Enter command ADD, SEARCH, EXIT: ", line, "ADSERCHXIT");
        if (line == "ADD") {
            _add();
        } else if (line == "SEARCH") {
            _search();
        } else if (line == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }
}