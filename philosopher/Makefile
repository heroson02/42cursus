SRCS =	main.c \
		ft_atoi.c \
		error.c	\
		utils.c
CC = gcc
CFLAGS= -Wextra -Werror -Wall
HEADER = includes
OBJ = $(SRCS:.c=.o)
LLDB = -g
ERRTEST = -g3 -fsanitize=address
NAME = philo

$(NAME) :  $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(LLDB) $(OBJ)
errtest :  $(OBJ)
	$(CC) $(CFLAGS) $(ERRTEST) -o $(NAME) $(LLDB) $(OBJ)

%o : %c
	$(CC) $(CFLAGS) $(LLDB) -c $< -I$(HEADER)

all : $(NAME)

bonus : server_bonus client_bonus

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all re bonus