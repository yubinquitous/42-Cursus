NAME = libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar crs
RM		= rm -f

SRCS	= ft_split.c \
		ft_isdigit.c \
		ft_atoi.c \

OBJS	= $(SRCS:.c=.o)

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
