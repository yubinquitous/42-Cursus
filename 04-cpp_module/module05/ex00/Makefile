NAME = a.out

SRCS = main.cpp \
	Bureaucrat.cpp \

OBJS = $(SRCS:%.cpp=%.o)

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)
.PHONY: all

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean: 
	rm -f $(OBJS)
.PHONY: clean

fclean: clean
	rm -f $(NAME)
.PHONY: fclean

re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY: re