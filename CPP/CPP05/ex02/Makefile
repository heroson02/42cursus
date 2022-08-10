SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp
NAME = Form
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)

re:
	make clean
	make all

.PHONY: all clean re