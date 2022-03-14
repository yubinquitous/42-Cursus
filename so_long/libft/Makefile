NAME = libft.a

CC		= gcc -fsanitize=address -g3
CFLAGS	= -Wall -Wextra -Werror
AR		= ar crs
RM		= rm -f

FILES	= get_next_line.c \
		get_next_line_utils.c
OBJS	= $(FILES:.c=.o)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

.PHONY:	all
all:	$(NAME)

.PHONY:	clean
clean:
		$(RM) $(OBJS)

.PHONY:	fclean
fclean:	clean
		$(RM) $(NAME)

.PHONY:	re
re:		fclean all
