NAME = so_long

SRCS	= src/main.c src/key_press.c src/move.c src/exit.c src/check.c src/init.c src/draw.c src/ft_exit.c
OBJS	= $(SRCS:%.c=%.o)
LIBFT 	= libft

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
CLIB	= -L./ -lmlx -framework OpenGL -framework AppKit
RM		= rm -f

.PHONY:	all
all:	$(NAME)

$(NAME):	$(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT).a $(LIBFT).a
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) $(LIBFT).a -o $(NAME)

.PHONY:	clean
clean:
	$(RM) $(OBJS) $(LIBFT)/*.o

.PHONY:	fclean
fclean:	clean
	$(RM) $(NAME) $(LIBFT).a

.PHONY:	re
re:	fclean all
