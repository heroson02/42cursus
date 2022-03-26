SRCS =				main.c \
					ft_atoi_ad.c \
					init.c \
					utils.c	\
					check.c	\
					routine.c
SRCS_BONUS =		main_bonus.c \
					ft_atoi_ad_bonus.c \
					init_bonus.c \
					utils_bonus.c	\
					check_bonus.c	\
					routine_bonus.c	\
					ft_itoa_bonus.c
CC = gcc
CFLAGS= -Wextra -Werror -Wall
HEADER = include
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)
NAME = philo
BONUS_NAME = philo_bonus

$(NAME) :  $(OBJ)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ)

%o : %c
	$(CC) $(CFLAGS) -g -c $< -I$(HEADER)

all : $(NAME)

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

bonus :   $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_BONUS)

re : fclean all

.PHONY : clean fclean all re bonus