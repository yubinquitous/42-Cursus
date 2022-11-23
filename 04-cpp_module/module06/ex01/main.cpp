#include "Serialization.hpp"

int main() {
    Serialization s;
    Data* data = new Data();

    data->_name = "test";
    uintptr_t raw = s.serialize(data);
    std::cout << (uintptr_t)data << std::endl;
    std::cout << raw << std::endl;

    Data* data2 = s.deserialize(raw);
    std::cout << "_name: " << data2->_name << std::endl;
    std::cout << ((data2 == data) ? "true" : "false") << std::endl;

    return 0;
}