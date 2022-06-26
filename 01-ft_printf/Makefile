# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubchoi <yubchoi@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 18:09:28 by yubchoi           #+#    #+#              #
#    Updated: 2022/01/01 17:32:08 by yubinquit        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS 		= ft_printf.c \
			  parse_arg.c \
			  check_format.c \
			  print_char.c \
			  print_nbr.c \
			  print_str.c \
			  utils.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc
RM			= rm -f

$(NAME)	: $(OBJS)
	$(AR) $(NAME) $(OBJS)

.PHONY	: all
all : $(NAME)

.PHONY	: clean
clean	:
	$(RM) $(OBJS)

.PHONY	: fclean
fclean	: clean
	$(RM) $(NAME)

.PHONY	: re
re		: fclean all
