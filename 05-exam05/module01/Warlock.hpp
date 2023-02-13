#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Warlock {
  private:
    std::string name;
    std::string title;

    Warlock();
    Warlock(Warlock const &src);
    Warlock &operator=(Warlock const &rhs);

    std::map<std::string, ASpell *> spells;

  public:
    Warlock(std::string const &name, std::string const &title);
    virtual ~Warlock();

    std::string const &getName(void) const;
    std::string const &getTitle(void) const;

    void setTitle(std::string const &title);

    void introduce(void) const;

    void learnSpell(ASpell *spell);
    void forgetSpell(std::string name);
    void launchSpell(std::string name, ATarget const &target);
};

#endif