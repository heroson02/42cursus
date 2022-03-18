/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:06:39 by yson              #+#    #+#             */
/*   Updated: 2022/03/18 23:37:18 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
	long long		ms;

	philo = argv;
	while (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->check);
		pthread_mutex_lock(&philo->info->finish_mutex);
		ms = get_time_ms() - philo->last_time_to_eat;
		if (ms >= philo->info->time_to_die && philo->info->finish == 0)
		{
			print_mutex(philo, "died");
			philo->info->finish = 1;
		}
		pthread_mutex_unlock(&philo->info->finish_mutex);
		pthread_mutex_unlock(&philo->check);
	}
	return (NULL);
}
