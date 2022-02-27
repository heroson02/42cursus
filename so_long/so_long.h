/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:44:57 by yson              #+#    #+#             */
/*   Updated: 2021/11/23 19:00:29 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define MAX_FD 256

# define KEY_W 13
# define KEY_A 0 
# define KEY_S 1 
# define KEY_D 2 
# define KEY_ESC 53
# define CELL_SIZE 100
# define KEY_PRESS 2
# define KEY_EXIT 17

typedef struct s_character
{
	int	x;
	int	y;
	int	collection;
	int	movement;
}	t_character;

typedef struct s_image
{
	int		width;
	int		height;
	void	*character_left;
	void	*character_right;
	void	*character_face;
	void	*character_back;
	void	*background;
	void	*collection;
	void	*wall;
	void	*exit;
}	t_image;

typedef struct map
{
	char	**info;
	int		width;
	int		height;
}	t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_image		image;
	t_character	user;
	t_map		map;
}	t_mlx;

typedef struct s_map_source
{
	int	player;
	int	collection;
	int	exit;
}	t_map_source;

int				get_next_line(int fd, char **line);
char			*ft_strdup(const char *src);
int				ft_strlen(const char *str);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *str, int c);
void			read_map(char *path, t_mlx *mlx);
void			check_map(t_mlx *mlx);
void			map_init(t_mlx *target);
void			draw_wall(t_mlx *target, int x, int y);
void			draw_bg(t_mlx *target, int x, int y);
void			draw_collection(t_mlx *target, int x, int y);
void			draw_player(t_mlx *target, int x, int y, int keycode);
void			draw_exit(t_mlx *target, int x, int y);
void			image_upload(t_mlx *target);
int				draw_map(t_mlx *target);
int				key_press(int keycode, t_mlx *target);
void			print_movement(int n);
int				quit_game(t_mlx *target);
void			game_clear(t_mlx *target);
void			error_exit(char *str);
void			screen_size_check(t_mlx *target);
int				check_end(int keycode, t_mlx *target);
int				check_collection(int keycode, t_mlx *target);
int				check_wall(int keycode, t_mlx *target);
int				wall_end_check(t_mlx *target, int x, int y);
void			user_init(t_mlx *target, t_map_source *source, int i, int j);
int				check_source_validity(char c);
#endif