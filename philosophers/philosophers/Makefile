SRCS =	main.c \
		ft_atoi.c \
		error.c	\
		utils.c	\
		check.c	\
		routine.c \
		init.c
CC = gcc
CFLAGS= -Wextra -Werror -Wall
HEADER = includes
OBJ = $(SRCS:.c=.o)
NAME = philo

$(NAME) :  $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%o : %c
	$(CC) $(CFLAGS) -c $< -I$(HEADER)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all re bonus