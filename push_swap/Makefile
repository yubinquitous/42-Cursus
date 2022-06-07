NAME = push_swap

SRCS	= src/main.c src/exit.c src/count.c src/init.c
OBJS	= $(SRCS:%.c=%.o)
LIBFT 	= libft

CC		= gcc -fsanitize=address -g3
CFLAGS	= -Wall -Werror -Wextra
CLIB	= -L./libft -lft 
RM		= rm -f

.PHONY:	all
all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C ./$(LIBFT)
	$(CC) $(CLIB) $(SRCS) -o $(NAME)

.PHONY:	clean
clean:
	$(MAKE) clean -C ./$(LIBFT)
	$(RM) $(OBJS)

.PHONY:	fclean
fclean:	clean
	$(MAKE) fclean -C ./$(LIBFT)
	$(RM) $(NAME)

.PHONY:	re
re:	fclean all
