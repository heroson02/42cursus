/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:06:39 by yson              #+#    #+#             */
/*   Updated: 2022/03/27 01:58:28 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosopher.h"

void	*check_goal(void *data)
{
	t_info	*info;

	info = (t_info *)data;
	while (!info->finish)
	{
		if (info->eat_amount_goal == info->num_of_philo)
		{
			pthread_mutex_lock(&info->print_mutex);
			info->finish = 1;
			pthread_mutex_unlock(&info->finish_mutex);
			usleep(100);
			break ;
		}
	}
	return (0);
}

// void	*monitor(void *data)
// {
// 	t_philo			*philo;
// 	long long		ms;

// 	philo = (t_philo *)data;
// 	while (!philo->info->finish)
// 	{
// 		// pthread_mutex_lock(&philo->check);
// 		ms = get_time_ms() - philo->last_time_to_eat;
// 		if (ms >= philo->info->time_to_die && philo->info->finish == 0)
// 		{
// 			if (philo->info->num_of_philo == 1)
// 				pthread_mutex_unlock(philo->right);
// 			print_mutex(philo, "died\t\t");
// 			// pthread_mutex_lock(&philo->info->print_mutex);
// 			philo->info->finish = 1;
// 			usleep(100);
// 			break ;
// 		}
// 		// pthread_mutex_unlock(&philo->check);
// 		usleep(100);
// 	}
// 	return (0);
// }

int	check_death(t_philo *philo)
{
	long long		ms;

	ms = get_time_ms() - philo->last_time_to_eat;
	// pthread_mutex_lock(&philo->info->print_mutex);
	if (ms >= philo->info->time_to_die && philo->info->finish == 0)
	{
		pthread_mutex_lock(&philo->info->death_mutex);
		print_mutex(philo, "died\t");
		// printf("%lld\t%d\tdied\t\t\t%d\n", get_time_ms() - philo->info->start_time, philo->name, philo->eat_amount);
		philo->info->finish = 1;
		pthread_mutex_unlock(&philo->info->finish_mutex);
		usleep(100);
		return (1);
	}
	// pthread_mutex_unlock(&philo->info->print_mutex);
	return (0);
}

void	*monitor(void *data)
{
	t_info			*info;
	int				i;

	i = 0;
	info = data;
	while (1)
	{
		if (info->finish)
			return (0);
		if (i == info->num_of_philo)
			i = 0;
		if (check_death(&info->philos[i]))
			return (0);
		i++;
		usleep(100);
	}
	return (0);
}
