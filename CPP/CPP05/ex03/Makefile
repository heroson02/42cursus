SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp	\
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp	\
		Intern.cpp
NAME = Form
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(FLAGS) -c $^ -o $@

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf *_shrubbery

fclean:
	make clean
	rm -rf $(NAME)

re:
	make clean
	make all

.PHONY: all clean re