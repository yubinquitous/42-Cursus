#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
    : name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {
    std::cout << this->name << ": My job here is done!\n";
    std::map<std::string, ASpell *>::iterator ite = this->spells.end();
    for (std::map<std::string, ASpell *>::iterator it = this->spells.begin();
         it != ite; ++it) {
        delete it->second;
    }
    this->spells.clear();
}

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
    if (spell) {
        this->spells.insert(
            std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
    }
}

void Warlock::forgetSpell(std::string name) {
    std::map<std::string, ASpell *>::iterator it = this->spells.find(name);
    if (it != this->spells.end()) {
        delete it->second;
        this->spells.erase(it);
    }
}

void Warlock::launchSpell(std::string name, ATarget const &target) {
    // std::vector<ASpell *>::iterator ite = this->spells.end();
    // for (std::vector<ASpell *>::iterator it = this->spells.begin(); it !=
    // ite;
    //      ++it) {
    //     if ((*it)->getName() == name) {
    //         (*it)->launch(target);
    //         return;
    //     }
    // }
    std::map<std::string, ASpell *>::iterator ite = this->spells.end();
    for (std::map<std::string, ASpell *>::iterator it = this->spells.begin();
         it != ite; ++it) {
        if (it->first == name) {
            it->second->launch(target);
            return;
        }
    }
}