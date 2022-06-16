NAME = push_swap
NAME_BONUS = checker

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
		
SRCS_BONUS	= src/checker/checker.c \
			src/count/count_init.c \
			src/init/init_util.c \
			src/init/init.c \
			src/exit.c \
			src/stack.c \
			src/index.c \
			src/command/push.c \
			src/command/rotate.c \
			src/command/rrotate.c \
			src/command/swap.c \
			libgnl/get_next_line.c \
			libgnl/get_next_line_utils.c \

OBJS	= $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

LIBFT 		= ./libft
GNL			= ./libgnl

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
CLIBFT	= -L./libft -lft 
CLIBGNL = -L./libgnl -lgnl
AR		= ar crs
RM		= rm -f

.PHONY:	all
all:	$(NAME)

.PHONY: bonus
bonus:	$(NAME_BONUS)

$(NAME):	$(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(CLIBFT) $(SRCS) -o $(NAME)

$(NAME_BONUS):	$(OBJS_BONUS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(GNL)
	$(CC) $(CFLAGS) $(CLIBFT) $(CLIBGNL) $(SRCS_BONUS) -o $(NAME_BONUS)

.PHONY:	clean
clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(GNL)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

.PHONY:	fclean
fclean:	clean
	$(MAKE) fclean -C ./$(LIBFT)
	$(MAKE) fclean -C ./$(GNL)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

.PHONY:	re
re:	$(MAKE) fclean 
	$(MAKE) all
