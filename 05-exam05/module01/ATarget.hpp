#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

class ASpell;

class ATarget {
  private:
    std::string type;

  public:
    ATarget();
    ATarget(std::string const &type);
    ATarget(ATarget const &rhs);
    ATarget &operator=(ATarget const &other);
    virtual ~ATarget();

    std::string const &getType(void) const;
    void getHitBySpell(ASpell const &aspell_ref) const;

    virtual ATarget *clone(void) const = 0;
};

#include "ASpell.hpp"

#endif