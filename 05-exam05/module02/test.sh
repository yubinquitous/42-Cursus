clang++ -fsanitize=address -g3 -Wall -Wextra -Werror -W -std=c++98 *.cpp -o start
./start
rm start