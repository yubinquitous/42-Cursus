NAME = pipex
NAME_BONUS = pipex

SRCS = src/pipex.c	\
	src/exit.c	\
	src/child.c \

OBJS = $(SRCS:%c=%o)

LIBFT = ./lib/libft
CC = gcc -g3 -fsanitize=address
#CFLAGS = -Wall -Werror -Wextra
CLIBFT = -L./lib/libft -lft
AR = ar crs
RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CLIBFT) $(SRCS) -o $(NAME)

.PHONY: clean
clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

.PHONY: re
re: $(MAKE) fclean
	$(MAKE) all
