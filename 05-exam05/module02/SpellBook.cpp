#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    std::map<std::string, ASpell *>::iterator it = this->spells.begin();
    std::map<std::string, ASpell *>::iterator ite = this->spells.end();
    while (it != ite) {
        delete it->second;
        ++it;
    }
    this->spells.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
    if (spell) {
        spells.insert(
            std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
    }
}

void SpellBook::forgetSpell(std::string const &name) {
    std::map<std::string, ASpell *>::iterator it = spells.find(name);
    if (it != spells.end())
        delete it->second;
    spells.erase(name);
}

ASpell *SpellBook::createSpell(std::string const &name) {
    std::map<std::string, ASpell *>::iterator it = spells.find(name);
    if (it != spells.end())
        return spells[name];
    return NULL;
}