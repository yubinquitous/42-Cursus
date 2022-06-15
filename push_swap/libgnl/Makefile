NAME = libgnl.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar crs
RM		= rm -f

FILES	= get_next_line.c \
		get_next_line_utils.c \

OBJS	= $(FILES:.c=.o)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

all:	$(NAME)
.PHONY:	all

clean:
		$(RM) $(OBJS)
.PHONY:	clean

fclean:	clean
		$(RM) $(NAME)
.PHONY:	fclean

re:		fclean all
.PHONY:	re