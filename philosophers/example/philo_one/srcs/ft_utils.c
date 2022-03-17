/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:26:58 by gpaeng            #+#    #+#             */
/*   Updated: 2022/03/16 16:47:43 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	ft_error(char *s)
{
	printf("%s\n", s);
	return (-1);
}

void	ft_printf(t_game *game, char *str, int id)
{
	pthread_mutex_lock(&(game->write));
	if (!(game->die))
	{
		printf("%lld ", ft_time() - game->start_time);
		printf("%d ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(game->write));
	return ;
}
