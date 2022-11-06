# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubin <yubchoi@student.42>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 21:26:03 by yubin             #+#    #+#              #
#    Updated: 2022/11/06 21:59:17 by yubin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp \
	PhoneBook.cpp \
	Contact.cpp

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
