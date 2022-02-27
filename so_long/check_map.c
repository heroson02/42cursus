/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:12:01 by yson              #+#    #+#             */
/*   Updated: 2021/11/23 19:27:22 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_edge_check(char *line, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			if (!check_source_validity(line[i]))
				error_exit("Error! Map has invalid source.");
			error_exit("Error! Maps should be surrounded by walls.");
		}
		i++;
	}
	if (ft_strlen(line) != mlx->map.width)
		error_exit("Error! The map must be rectangular.");
}

void	wall_middle_check(char *line, t_mlx *mlx)
{
	int	len;

	len = ft_strlen(line) - 1;
	if (len < 1)
		error_exit("Error! The width of the map must be at least 2.");
	if (ft_strlen(line) != mlx->map.width)
		error_exit("Error! The map must be rectangular.");
	if (line[0] != '1' || line[len] != '1')
		error_exit("Error! Maps should be surrounded by walls.");
}

void	init_map_source(t_map_source *source)
{
	source->collection = 0;
	source->exit = 0;
	source->player = 0;
}

void	count_map_source(t_map_source *source, t_mlx *target)
{
	int	i;
	int	j;

	i = -1;
	while (++i < target->map.height)
	{
		j = -1;
		while (++j < target->map.width)
		{
			if (!check_source_validity(target->map.info[i][j]))
				error_exit("Error! Map has invalid source.");
			if (target->map.info[i][j] == 'C')
				source->collection++;
			else if (target->map.info[i][j] == 'P')
				user_init(target, source, i, j);
			else if (target->map.info[i][j] == 'E')
				source->exit++;
		}
	}
	if (!((source->collection >= 1) && (source->exit >= 1)
			&& (source->player == 1)))
		error_exit("Error! Map must have at least one 'E', 'C', 'P'.");
}

void	check_map(t_mlx *target)
{
	int				i;
	t_map_source	source;

	i = 0;
	init_map_source(&source);
	wall_edge_check(target->map.info[0], target);
	while (++i < target->map.height - 1)
		wall_middle_check(target->map.info[i], target);
	wall_edge_check(target->map.info[i], target);
	count_map_source(&source, target);
	target->user.collection = source.collection;
	screen_size_check(target);
}
