NAME = UnnecessaryViolence

CC = c++
CFLAGS =  -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp \
	HumanA.cpp \
	HumanB.cpp \
	Weapon.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
.PHONY: all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)
.PHONY: clean

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY: re