NAME = a.out

SRC = main.cpp \
	Animal.cpp \
	Cat.cpp \
	Dog.cpp \
	Brain.cpp

OBJ = $(SRC:%.cpp=%.o)

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)
.PHONY: all

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o  $@ $^

clean:
	rm -f $(OBJ)
.PHONY: clean

fclean: clean
	rm -f $(NAME)
.PHONY: fclean

re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY: re