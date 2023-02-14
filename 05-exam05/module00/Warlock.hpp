#pragma once

#include <iostream>
#include <string>

class Warlock {
  private:
    std::string _name;
    std::string _title;

  public:
    const std::string &getName(void) const { return this->_name; }
    const std::string &getTitle(void) const { return this->_title; }

    void setTitle(const std::string &title) { this->_title = title; }

    Warlock(const std::string &name, const std::string &title)
        : _name(name), _title(title) {
        std::cout << _name << ": This looks like another boring day."
                  << std::endl;
    }

    ~Warlock() { std::cout << _name << ": My job here is done!" << std::endl; }

    void introduce() const {
        std::cout << _name << ": I am " << _name << ", " << _title << "!"
                  << std::endl;
    }
};