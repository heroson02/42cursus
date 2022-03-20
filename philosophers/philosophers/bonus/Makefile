SRCS =	main_bonus.c \
		ft_atoi_ad_bonus.c \
		init_bonus.c \
		utils_bonus.c	\
		check_bonus.c	\
		routine_bonus.c
SRCS_BONUS = 
CC = gcc
CFLAGS= -Wextra -Werror -Wall
HEADER = includes
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)
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

bonus :   $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_BONUS)

re : fclean all

.PHONY : clean fclean all re bonus