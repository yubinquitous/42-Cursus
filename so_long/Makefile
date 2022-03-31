NAME = so_long

SRCS	= src/main.c src/key_press.c src/move.c src/exit.c src/check.c src/init.c src/draw.c
OBJS	= $(SRCS:%.c=%.o)
LIBFT 	= libft
MLX		= mlx

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
CLIB	= -L./mlx -lmlx -L./libft -lft \
		-framework OpenGL -framework AppKit
RM		= rm -f

.PHONY:	all
all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C ./$(LIBFT)
	$(MAKE) -C ./$(MLX)	
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)

.PHONY:	clean
clean:
	$(MAKE) clean -C ./$(LIBFT)
	$(MAKE) clean -C ./$(MLX)
	$(RM) $(OBJS)

.PHONY:	fclean
fclean:	clean
	$(MAKE) fclean -C ./$(LIBFT)
	$(RM) $(NAME)

.PHONY:	re
re:	fclean all
