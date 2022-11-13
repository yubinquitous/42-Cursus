NAME = a.out

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp \
	ClapTrap.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
.PHONY: all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

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