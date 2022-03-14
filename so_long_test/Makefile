NAME	= so_long

SRCS	= src/main.c
OBJS	= $(SRCS:%.c=%.o)
LIBFT 	= libft

CC		= gcc -fsanitize=address -g3
CFLAGS	= -Wall -Werror -Wextra
CLIB	= -L./src -lmlx
RM		= rm -f

.PHONY:	all
all:	$(NAME)

%.o:	%.c
	$(CC) $(CLIB) -c $< -o $@

$(NAME):	$(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT).a $(LIBFT).a
	$(CC) $(CLIB) $(SRCS) $(LIBFT).a -o $(NAME)

.PHONY:	clean
clean:
	$(RM) $(OBJS)

.PHONY:	fclean
fclean:	clean
	$(RM) $(NAME) $(LIBFT).a

.PHONY:	re
re:	fclean all