NAME = push_swap

SRCS	= src/main.c \
		src/exit.c \
		src/stack.c \
		src/index.c \
		src/command/push.c \
		src/command/rotate.c \
		src/command/rrotate.c \
		src/command/swap.c \
		src/count/count_init.c \
		src/count/count_sort.c \
		src/init/init_util.c \
		src/init/init.c \
		src/sort/sort_a.c \
		src/sort/sort_five.c \
		src/sort/sort_greedy.c \
		src/sort/sort_three.c \
		src/sort/sort.c \
		src/sort/do_sort.c \
		src/push_num/push_num_to_a.c \
		src/push_num/push_num_to_b.c \
		
OBJS	= $(SRCS:%.c=%.o)
LIBFT 	= libft
CC		= gcc
# CFLAGS	= -Wall -Werror -Wextra
CLIB	= -L./libft -lft 
RM		= rm -f

all:	$(NAME)
.PHONY:	all

$(NAME):	$(OBJS)
	$(MAKE) -C ./$(LIBFT)
	$(CC) $(CLIB) $(SRCS) -o $(NAME)

clean:
	$(MAKE) clean -C ./$(LIBFT)
	$(RM) $(OBJS)
.PHONY:	clean

fclean:	clean
	$(MAKE) fclean -C ./$(LIBFT)
	$(RM) $(NAME)
.PHONY:	fclean

re:	$(MAKE) fclean 
	$(MAKE) all
.PHONY:	re