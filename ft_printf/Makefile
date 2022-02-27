# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 00:34:57 by yson              #+#    #+#              #
#    Updated: 2021/09/10 19:09:18 by yson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	convert_base.c		\
		ft_printf.c			\
		ft_uitoa.c			\
		main.c				\
		print_char.c		\
		print_hex.c			\
		print_int.c			\
		print_pointer.c		\
		print_string.c		\
		print_uint.c		\
		print_pointer.c		\
		print_percent.c
		
CC = gcc
CFLAGS= -Wextra -Werror -Wall
AR = ar -rcs
HEADER = includes
LIBDIR = libft
OBJ = $(SRCS:.c=.o)
NAME = libftprintf.a

$(NAME) : $(OBJ)
	make all -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

%o : %c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER) -I$(LIBDIR)

all : $(NAME)

clean :
	make clean -C ./libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all re
