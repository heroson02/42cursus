# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 19:54:30 by yson              #+#    #+#              #
#    Updated: 2021/09/25 16:26:46 by yson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVERSRCS = 	server_main.c	\
				ft_putnbr_fd.c	\
				ft_putchar_fd.c
CLIENTSRCS =	client_main.c	\
				ft_atoi.c		\
				ft_itoa.c
SERVERSRCS_BONUS = 	server_main_bonus.c	\
					ft_putnbr_fd.c	\
					ft_putchar_fd.c
CLIENTSRCS_BONUS =	client_main_bonus.c	\
					ft_atoi.c		\
					ft_itoa.c
CC = gcc
CFLAGS= -Wextra -Werror -Wall
HEADER = includes
SERVEROBJ = $(SERVERSRCS:.c=.o)
CLIENTOBJ = $(CLIENTSRCS:.c=.o)
SERVEROBJ_BONUS = $(SERVERSRCS_BONUS:.c=.o)
CLIENTOBJ_BONUS = $(CLIENTSRCS_BONUS:.c=.o)
NAME = minitalk
SERVER = server
CLIENT = client

$(NAME) :  $(SERVER) $(CLIENT)

$(SERVER) : $(SERVEROBJ)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVEROBJ)

$(CLIENT) : $(CLIENTOBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENTOBJ)

%o : %c
	$(CC) $(CFLAGS) -c $< -I$(HEADER)

all : $(NAME)

server_bonus : $(SERVEROBJ_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVEROBJ_BONUS)

client_bonus : $(CLIENTOBJ_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENTOBJ_BONUS)

bonus : server_bonus client_bonus

clean :
	rm -rf $(SERVEROBJ) $(CLIENTOBJ)
	rm -rf $(SERVEROBJ_BONUS) $(CLIENTOBJ_BONUS)

fclean : clean
	rm -rf $(SERVER) $(CLIENT)

re : fclean all

.PHONY : clean fclean all re bonus