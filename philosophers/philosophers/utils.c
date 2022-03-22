/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:46:06 by yson              #+#    #+#             */
/*   Updated: 2022/03/22 17:56:51 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_mutex(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	if (!philo->info->finish)
	{
		printf("%lld\t", get_time_ms() - philo->info->start_time);
		printf("%d\t", philo->name + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&philo->info->print_mutex);
}
