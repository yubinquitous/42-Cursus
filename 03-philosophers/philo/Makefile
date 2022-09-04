NAME = philo

SRCS = init_utils.c \
		init.c \
		observer_thread.c \
		philo_action.c \
		philo_thread_utils.c \
		philo_thread.c \
		main.c \
		run.c \
		utils.c \
		
OBJS = $(SRCS:%.c=%.o)

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar crs
RM		= rm -f

.PHONY	: all
all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

.PHONY	: clean
clean	:
	$(RM) $(OBJS)

.PHONY	: fclean
fclean	: clean
	$(RM) $(NAME)

.PHONY	: re
re		: $(MAKE) fclean
		$(MAKE) all