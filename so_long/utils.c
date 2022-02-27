/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:57:08 by yson              #+#    #+#             */
/*   Updated: 2021/11/23 19:10:12 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	char	a[1];

	a[0] = c;
	write(fd, a, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

void	print_movement(int n)
{
	ft_putnbr_fd(n, 1);
	write(1, " move\n", 6);
}

void	user_init(t_mlx *target, t_map_source *source, int i, int j)
{
	target->user.x = j;
	target->user.y = i;
	source->player++;
}

int	check_source_validity(char c)
{
	if (c == 'C' || c == 'P' || c == 'E' || c == '0' || c == '1')
		return (1);
	return (0);
}
