NAME = push_swap

SRCS	= src/main.c \
		src/exit.c \
		src/count.c \
		src/init.c \
		src/sort.c \
		src/sort_three.c \
		src/command/push.c \
		src/command/rotate.c \
		src/command/rrotate.c \
		src/command/swap.c \
		src/stack_util.c
		
OBJS	= $(SRCS:%.c=%.o)
LIBFT 	= libft
#-fsanitize=address -g3
CC		= gcc -fsanitize=address -g3
# CFLAGS	= -Wall -Werror -Wextra
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
