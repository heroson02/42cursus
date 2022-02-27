/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:17:14 by yson              #+#    #+#             */
/*   Updated: 2021/11/19 02:24:12 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_check(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	if (path[i--] == 'r')
	{
		if (path[i--] == 'e')
		{
			if (path[i--] == 'b')
			{
				if (path[i] == '.')
					return ;
			}
		}
	}
	error_exit("Error! The map file must be an .ber extension.");
}

int	check_line(char *path)
{
	int		height_count;
	char	c;
	int		is_read;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	height_count = 0;
	while (1)
	{
		is_read = read(fd, &c, 1);
		if (is_read == 0)
			break ;
		if (is_read < 0)
			return (0);
		if (c == '\n')
			height_count++;
	}
	close(fd);
	return (height_count);
}

int	mlx_struct_init(char *path, t_mlx *target)
{
	int	height_count;

	height_count = check_line(path);
	target->map.height = height_count;
	target->user.movement = 0;
	if (height_count <= 0)
		return (0);
	target->map.info = malloc(sizeof(char *) * (height_count + 1));
	if (!(target->map.info))
		error_exit("Error! Map error.");
	return (1);
}

void	read_map(char *path, t_mlx *target)
{
	int	i;
	int	fd;
	int	result;

	path_check(path);
	result = mlx_struct_init(path, target);
	fd = open(path, O_RDONLY);
	i = 0;
	if (fd == -1 || !result)
		error_exit("Error! Not valid file.");
	while (1)
	{
		result = get_next_line(fd, &(target->map.info[i]));
		if (result == -1)
			error_exit("Error");
		if (result == 0)
			break ;
		i++;
	}
	close(fd);
	target->map.width = ft_strlen(target->map.info[0]);
}
