# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 00:35:14 by yson              #+#    #+#              #
#    Updated: 2021/07/20 00:35:28 by yson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_atoi.c \
		ft_bzero.c\
		ft_calloc.c	\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memccpy.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_strchr.c	\
		ft_strdup.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	
		
BONUSSRCS = ft_lstnew.c		\
			ft_lstadd_front.c	\
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c	\
			ft_lstiter.c	\
			ft_lstmap.c
CC = gcc
CFLAGS= -Wextra -Werror -Wall
AR = ar -rcs
OBJ = $(SRCS:.c=.o)
BONUSOBJ = $(BONUSSRCS:.c=.o)
NAME = libft.a

$(NAME) : $(OBJ) 
	$(AR) $(NAME) $(OBJ)

%o : %c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJ) $(BONUSOBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(OBJ) $(BONUSOBJ)
	$(AR) $(NAME) $(OBJ) $(BONUSOBJ)

.PHONY : clean fclean all re bonus
