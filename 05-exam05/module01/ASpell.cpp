#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects)
    : name(name), effects(effects) {}

ASpell::ASpell(ASpell const &other) : name(other.name), effects(other.effects) {
    *this = other;
}

ASpell &ASpell::operator=(ASpell const &rhs) {
    this->name = rhs.name;
    this->effects = rhs.effects;
    return (*this);
}

ASpell::~ASpell() {}

std::string const &ASpell::getName(void) const { return this->name; }

std::string const &ASpell::getEffects(void) const { return this->effects; }

void ASpell::launch(ATarget const &target) const {
    target.getHitBySpell((*this));
}