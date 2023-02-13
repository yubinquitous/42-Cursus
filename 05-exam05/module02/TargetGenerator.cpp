#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
    std::map<std::string, ATarget *>::iterator ite = this->targets.end();
    std::map<std::string, ATarget *>::iterator it = this->targets.begin();

    while (it != ite) {
        delete it->second;
        ++it;
    }
    this->targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *target) {
    if (target)
        targets.insert(std::pair<std::string, ATarget *>(target->getType(),
                                                         target->clone()));
}

void TargetGenerator::forgetTargetType(const std::string &target) {
    std::map<std::string, ATarget *>::iterator it = targets.find(target);
    if (it != targets.end())
        delete it->second;
    targets.erase(target);
}

ATarget *TargetGenerator::createTarget(const std::string &target) {
    std::map<std::string, ATarget *>::iterator it = targets.find(target);
    if (it != targets.end())
        return targets[target];
    return NULL;
}