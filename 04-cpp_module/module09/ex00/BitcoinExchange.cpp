#include "BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
        std::cerr << "Error: could not open file '" << filename << std::endl;

    std::getline(file, line); // 헤더는 건너뛰기
    while (std::getline(file, line)) {
        std::string date;
        std::string exchange_rate;
        double rate;

        std::string::size_type delimiter_pos = line.find(',');
        if (delimiter_pos == std::string::npos) {
            std::cerr << "Error: Invalid database format => " << line
                      << std::endl;
        }

        date = line.substr(0, delimiter_pos);
        exchange_rate = line.substr(delimiter_pos + 1);

        try {
            rate = std::stod(exchange_rate);
        } catch (std::invalid_argument &e) {
            std::cerr << "Error: Invalid exchange rate => " << exchange_rate
                      << std::endl;
            continue;
        }

        _database[date] = rate;
    }
}

void BitcoinExchange::exchange(const std::string &filename) const {
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
        std::cerr << "Error: could not open file '" << filename << std::endl;

    std::getline(file, line); // 헤더는 건너뛰기
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        double value;
        char delimiter;

        if (!(ss >> date >> delimiter >> value)) {
            std::cerr << "Error: Bad input => " << std::endl;
            continue;
        }

        // Date check
        if (!isValidInputDate(date)) {
            std::cerr << "Error: Invalid date => " << date << std::endl;
            continue;
        }

        if (delimiter != '|') {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue;
        }

        if (!isValidInputValue(value))
            continue;

        float rate = getExchangeRate(date);
        if (rate == -1) {
            std::cerr << "Error: No exchange rate found for date " << date
                      << std::endl;
            continue;
        }

        // print result
        std::cout << date << " => " << value << " = " << value * rate
                  << std::endl;
    }
}

bool BitcoinExchange::isValidInputDate(const std::string &date) const {
    if (date.size() != 10) {
        return false;
    }

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (year.size() != 4 || month.size() != 2 || day.size() != 2) {
        return false;
    }

    if (std::count_if(year.begin(), year.end(), ::isdigit) != 4) {
        return false;
    }

    if (std::count_if(month.begin(), month.end(), ::isdigit) != 2) {
        return false;
    }

    if (std::count_if(day.begin(), day.end(), ::isdigit) != 2) {
        return false;
    }

    if (std::stoi(month) < 1 || std::stoi(month) > 12) {
        return false;
    }

    if (std::stoi(day) < 1 || std::stoi(day) > 31) {
        return false;
    }

    return true;
}

bool BitcoinExchange::isValidInputValue(const float value) const {
    if (value <= 0) {
        std::cerr << "Error: not a positive number" << std::endl;
        return false;
    }

    if (value > 1000) {
        std::cerr << "Error: too large a number" << std::endl;
        return false;
    }
    return true;
}

float BitcoinExchange::getExchangeRate(const std::string &date) const {
    // 가장 가까운 이전 날짜를 찾기 위한 로직을 여기에 구현하십시오.
    std::map<std::string, double>::const_iterator it =
        _database.lower_bound(date);
    if (it != _database.end()) {
        return it->second;
    } else if (!_database.empty()) {
        return (--it)->second;
    }

    return -1;
}