# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 13:49:16 by yubchoi           #+#    #+#              #
#    Updated: 2022/07/01 13:49:21 by yubchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex

SRCS = src/pipex.c	\
	src/exit.c	\
	src/child.c \
	src/parent.c \
	src/utils.c \
	src/find.c \

OBJS = $(SRCS:%c=%o)

LIBFT = ./lib/libft
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CLIBFT = -L./lib/libft -lft
AR = ar crs
RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(CLIBFT) $(SRCS) -o $(NAME)

.PHONY: clean
clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

.PHONY: re
re: $(MAKE) fclean
	$(MAKE) all
