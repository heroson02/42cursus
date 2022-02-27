SRCS =	check_map.c				\
		get_next_line.c			\
		get_next_line_utils.c	\
		main.c					\
		read_map.c				\
		map_init.c				\
		draw_map.c				\
		draw.c					\
		image_upload.c			\
		key_press_event.c		\
		utils.c					\
		game_exit.c				\
		screen_size_check.c		\
		check_condition.c
CC = gcc
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wextra -Werror -Wall
MLX_LIB = libmlx.dylib
OBJ = $(SRCS:.c=.o)
NAME = so_long

$(NAME) : $(OBJ) $(MLX_LIB)
	$(CC) $(MLXFLAGS) $(SRCS) -o $(NAME) $(MLX_LIB)

%o : %c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJ)
	make clean -C mlx
	rm -rf $(MLX_LIB)

$(MLX_LIB) : 
	make -C mlx
	cp mlx/$(MLX_LIB) $(MLX_LIB)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all re