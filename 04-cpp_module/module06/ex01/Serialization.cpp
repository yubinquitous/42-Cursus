#include "Serialization.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serialization::Serialization() {}

Serialization::Serialization(const Serialization& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serialization::~Serialization() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serialization& Serialization::operator=(Serialization const& rhs) {
    if (this != &rhs) {
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t Serialization::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialization::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */