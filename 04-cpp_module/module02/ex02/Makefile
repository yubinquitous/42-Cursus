NAME = a.out

SRC = main.cpp \
	  Fixed.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)
.PHONY: all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
.PHONY: clean

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
.PHONY: fclean

re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY: re