#include "ATarget.hpp"

ATarget::ATarget(std::string const &type) { this->type = type; }

ATarget::ATarget(ATarget const &rhs) { *this = rhs; }

ATarget::~ATarget() {}

ATarget &ATarget::operator=(ATarget const &other) {
    this->type = other.type;
    return (*this);
}

std::string const &ATarget::getType(void) const { return this->type; }

void ATarget::getHitBySpell(ASpell const &aspell_ref) const {
    std::cout << this->type << " has been " << aspell_ref.getEffects() << "!\n";
}