#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    void exchange(const std::string &filename) const;

  private:
    std::map<std::string, double> _database;

    float getExchangeRate(const std::string &date) const;
    bool isValidInputDate(const std::string &date) const;
    bool isValidInputValue(const float value) const;
};

#endif /* ************************************************* BITCOINEXCHANGE_H  \
        */