#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
    : name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() { std::cout << this->name << ": My job here is done!\n"; }

std::string const &Warlock::getName(void) const { return this->name; }

std::string const &Warlock::getTitle(void) const { return this->title; }

void Warlock::setTitle(std::string const &title) { this->title = title; }

void Warlock::introduce(void) const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title
              << "!\n";
}

void Warlock::learnSpell(ASpell *spell) {
    // std::vector<ASpell *>::iterator ite = this->spells.end();
    // for (std::vector<ASpell *>::iterator it = this->spells.begin(); it !=
    // ite;
    //      ++it) {
    //     if ((*it)->getName() == spell->getName()) {
    //         return;
    //     }
    // }
    // this->spells.push_back(spell->clone());
    book.learnSpell(spell);
}

void Warlock::forgetSpell(std::string name) { book.forgetSpell(name); }

void Warlock::launchSpell(std::string name, ATarget const &target) {
    ATarget const *tmp = 0;
    if (tmp == &target)
        return;
    ASpell *spell = book.createSpell(name);
    if (spell)
        spell->launch(target);
}