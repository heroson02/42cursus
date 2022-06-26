NAME = megaphone
CPP = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp

all : $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(SRCS) $(FLAGS) -o $(NAME)

clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re