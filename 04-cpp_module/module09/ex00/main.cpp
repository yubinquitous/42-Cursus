#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("data.csv");
    std::vector<std::vector<std::string> > data;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> lineData;
        std::stringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ',')) {
            lineData.push_back(cell);
        }

        data.push_back(lineData);
    }

    for (std::vector<std::vector<std::string> >::iterator it = data.begin();
         it != data.end(); ++it) {
        for (std::vector<std::string>::iterator it2 = it->begin();
             it2 != it->end(); ++it2) {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
