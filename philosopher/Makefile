SRCS = 
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

bonus : server_bonus client_bonus

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all re bonus