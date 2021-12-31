# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubchoi <yubchoi@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 18:09:28 by yubchoi           #+#    #+#              #
#    Updated: 2021/12/31 18:28:13 by yubchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS 		= ft_printf.c \
			  parse_arg.c \
			  check_format.c \
			  print_arg.c \

LIBFT 		= libft
LIBFT_LIB	= libft.a

INCS		= .

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc
RM			= rm -f

.c.o	:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME)	: $(OBJS)
	make all -C $(LIBFT)
	cp ./$(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

.PHONY	: all
all : $(NAME)

.PHONY	: clean
clean	:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

.PHONY	: fclean
fclean	: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

.PHONY	: re
re		: fclean all
