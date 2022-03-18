/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:06:39 by yson              #+#    #+#             */
/*   Updated: 2022/03/18 22:09:54 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_philo_msg(t_philo *philo, char *str)
{
	long long		ms;
	struct timeval	now;

	pthread_mutex_lock(&philo->info->finish_mutex);
	gettimeofday(&now, NULL);
	ms = time_to_ms(now) - time_to_ms(philo->info->start_time);
	if (!philo->info->finish)
		printf("%lld\t%d\t %s\n", ms, philo->name + 1, str);
	pthread_mutex_unlock(&philo->info->finish_mutex);
}

void	*monitor_each_must_eat(void *argv)
{
	t_info	*info;

	info = argv;
	while (!info->finish)
	{
		pthread_mutex_lock(&info->finish_mutex);
		if (info->eat_amount_goal == info->num_of_philo)
			info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
	}
	return (NULL);
}

void	*monitor(void *argv)
{
	t_philo			*philo;
	struct timeval	now;
	long long		ms;

	philo = argv;
	while (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->check);
		pthread_mutex_lock(&philo->info->finish_mutex);
		gettimeofday(&now, NULL);
		ms = time_to_ms(now) - time_to_ms(philo->last_time_to_eat);
		gettimeofday(&now, NULL);
		if (ms >= philo->info->time_to_die && philo->info->finish == 0)
		{
			printf("%lld\t%d\t %s\n", \
				time_to_ms(now) - time_to_ms(philo->info->start_time), \
				philo->name + 1, "died");
			philo->info->finish = 1;
		}
		pthread_mutex_unlock(&philo->info->finish_mutex);
		pthread_mutex_unlock(&philo->check);
	}
	return (NULL);
}
