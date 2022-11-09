#include <string.h>

#include <fstream>
#include <iostream>

int main(int ac, char **av) {
    if (ac != 4) {
        std::cout << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
        return 1;
    }

    std::string filename(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);

    std::ifstream ifs;
    ifs.open(filename);
    if (!ifs) {
        std::cout << "Error: cannot open file " << filename << std::endl;
        return 1;
    }

    if (s1.empty()) {
        std::cout << "Error: s1 and s2 must not be empty" << std::endl;
        return 1;
    }

    std::string line;
    std::ofstream ofs;

    ofs.open(filename + ".replace");
    if (!ofs) {
        std::cout << "Error: cannot open file " << filename << ".replace"
                  << std::endl;
        return 1;
    }

    while (std::getline(ifs, line)) {
        int pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            // replace 대신 erase + insert
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        ofs << line;
        if (!ifs.eof()) ofs << std::endl;
    }
    ifs.close();
    ofs.close();

    return 0;
}