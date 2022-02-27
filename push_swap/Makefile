SRCS =	ft_atoi_ad.c \
		lst_util.c	\
		main.c	\
		op_push_swap.c	\
		op_reverse_rotate.c	\
		op_rotate.c	\
		push_pop.c	\
		rotate.c	\
		source_condition_check.c	\
		swap.c	\
		error_handling.c	\
		lst_util2.c	\
		lst_util3.c	\
		send_recover.c \
		sort_a_to_b.c \
		sort_b_to_a.c \
		sort_case3_a.c	\
		sort_case3_b.c	\
		sort_low_number.c \
		get_max_min_data.c	\
		sort_case5.c	\
		sort_five.c	\
		sort_three_a_b.c

CC = gcc
CFLAGS= -Wextra -Werror -Wall
HEADER = includes
PRINTFDIR = ft_printf
LIBDIR = ft_printf/libft
LIBFT = libftprintf.a
OBJ = $(SRCS:.c=.o)
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ)
	make all -C ./ft_printf
	mv	ft_printf/$(LIBFT) .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%o : %c
	$(CC) $(CFLAGS) -c $< -I$(HEADER) -I$(LIBDIR)

clean :
	make fclean -C ./ft_printf/libft
	make fclean -C ./ft_printf
	rm -rf $(LIBFT)
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all re
