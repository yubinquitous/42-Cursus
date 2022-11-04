# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubin <yubchoi@student.42>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 19:05:11 by yubin             #+#    #+#              #
#    Updated: 2022/11/04 19:08:20 by yubin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all:	$(NAME)
.PHONY:	all 

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
.PHONY: clean

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
.PHONY:	fclean

re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY:	re