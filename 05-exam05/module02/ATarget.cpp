#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const &type) : type(type) {}

ATarget::ATarget(ATarget const &src) : type(src.type) { *this = src; }

ATarget::~ATarget() {}

ATarget &ATarget::operator=(ATarget const &rhs) {
    this->type = rhs.type;
    return (*this);
}

std::string const &ATarget::getType(void) const { return this->type; }

void ATarget::getHitBySpell(ASpell const &spell) const {
    std::cout << this->type << " has been " << spell.getEffects() << "!\n";
}