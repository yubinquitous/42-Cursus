#include "PhoneBook.hpp"

#include <stdlib.h>

#include <iomanip>  // std::setw

PhoneBook::PhoneBook() { _idx = 0; }

PhoneBook::~PhoneBook() {}

std::string PhoneBook::_shorten(std::string str) {
    if (str.length() > 10) {
        str = str.substr(0, 9);
        str.append(".");
    }
    return (str);
}

bool PhoneBook::_isValidInputIdx(std::string str, int &num) {
    if (str.length() != 1) {
        std::cout << "Error: Invalid input" << std::endl;
        return (false);
    }
    num = str[0] - '0';
    if (num < 0 || num > 7) {
        std::cout << "Error: Invalid index" << std::endl;
        return (false);
    }
    return (true);
}

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
        _contacts[idx].setFirstName(firstName);
        _contacts[idx].setLastName(lastName);
        _contacts[idx].setNickname(nickname);
        _contacts[idx].setPhoneNumber(phoneNumber);
        _contacts[idx].setSecret(secret);
        _idx += 1;
    } else {
        std::cout << "Error: Invalid input" << std::endl;
    }
}

void PhoneBook::_search() {
    int idx = _idx % 8;
    int num = 0;
    std::string line;

    std::cout << "     index|first name| last name|  nickname|" << std::endl;
    for (int i = 0; i < 8; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << _shorten(_contacts[i].getFirstName())
                  << "|";
        std::cout << std::setw(10) << _shorten(_contacts[i].getLastName())
                  << "|";
        std::cout << std::setw(10) << _shorten(_contacts[i].getNickname())
                  << "|";
        std::cout << std::endl;
    }

    _readLine("Enter index: ", line, "0123456789");
    if (!_isValidInputIdx(line, num)) return;
    std::cout << "First Name: " << _contacts[num].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[num].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[num].getNickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[num].getPhoneNumber()
              << std::endl;
    std::cout << "Darkest Secret: " << _contacts[num].getSecret() << std::endl;
}

void PhoneBook::run() {
    std::string line;

    while (1) {
        line = "";
        if (!_readLine("Enter command ADD, SEARCH, EXIT: ", line,
                       "ADSERCHXIT")) {
            std::cout << "Error: Invalid input" << std::endl;
            continue;
        }
        if (line == "ADD") {
            _add();
        } else if (line == "SEARCH") {
            _search();
        } else if (line == "EXIT") {
            break;
        }
    }
}