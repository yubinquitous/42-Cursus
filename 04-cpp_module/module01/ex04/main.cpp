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
    ifs.open(filename, std::ios::in);
    if (!ifs) {
        std::cout << "Error: cannot open file " << filename << std::endl;
        return 1;
    }

    if (s1.empty()) {
        std::cout << "Error: s1 and s2 must not be empty" << std::endl;
        return 1;
    }

    std::string line;
    std::string replace_line;
    while (std::getline(ifs, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            // replace 대신 erase + insert
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        replace_line += line;
        replace_line += "\n";
    }
    ifs.close();

    std::ofstream ofs;
    ofs.open(filename + ".replace", std::ios::out);
    if (!ofs) {
        std::cout << "Error: cannot open file " << filename << ".replace"
                  << std::endl;
        return 1;
    }
    ofs << replace_line;
    ofs.close();

    return 0;
}