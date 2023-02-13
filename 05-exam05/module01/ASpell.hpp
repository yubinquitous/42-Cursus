#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget;

class ASpell {
  protected:
    std::string name;
    std::string effects;

  public:
    ASpell();
    ASpell(std::string const &name, std::string const &effects);
    ASpell(ASpell const &src);
    virtual ~ASpell();

    ASpell &operator=(ASpell const &rhs);

    std::string const &getName(void) const;
    std::string const &getEffects(void) const;

    void launch(ATarget const &target) const;

    virtual ASpell *clone(void) const = 0;
};

#include "ATarget.hpp"

#endif