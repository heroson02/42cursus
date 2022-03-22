SRCS_NAME =			src/main.c \
				src/ft_atoi_ad.c \
				src/init.c \
				src/utils.c	\
				src/check.c	\
				src/routine.c
SRCS_BONUS_NAME =	src_bonus/main_bonus.c \
				src_bonus/ft_atoi_ad_bonus.c \
				src_bonus/init_bonus.c \
				src_bonus/utils_bonus.c	\
				src_bonus/check_bonus.c	\
				src_bonus/routine_bonus.c	\
				src_bonus/ft_itoa.c
CC = gcc
CFLAGS= -Wextra -Werror -Wall
HEADER = include
OBJ = $(SRCS_NAME:.c=.o)
OBJ_BONUS = $(SRCS_BONUS_NAME:.c=.o)
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
SRCS_DIR = src
SRCS_BONUS_DIR = src_bonus
SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR), $(SRCS_BONUS_NAME))
NAME = philo
BONUS_NAME = philo_bonus

$(NAME) :  $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%o : %c
	$(CC) $(CFLAGS) -c $< -I$(HEADER)

all : $(NAME)

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

bonus :   $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_BONUS)

re : fclean all

.PHONY : clean fclean all re bonus