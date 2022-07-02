# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 17:12:48 by yubchoi           #+#    #+#              #
#    Updated: 2022/07/02 18:08:37 by yubchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar crs
RM		= rm -f

SRCS	= ft_strdup.c \
	ft_strncmp.c \
	ft_strlen.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strchr.c \

OBJS = $(SRCS:.c=.o)

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
re:	$(MAKE) fclean
	$(MAKE) all