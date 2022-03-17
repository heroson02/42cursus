/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:07:23 by yson              #+#    #+#             */
/*   Updated: 2022/03/17 16:54:34 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating(t_info *info)
{
	long long current_time;
	long long start_eat_time;
	long long time_to_eat;

	time_to_eat = (long long)info->time_to_eat;
	start_eat_time = get_time_ms();
	while (!info->die)
	{
		current_time = get_time_ms();
		if ((current_time - start_eat_time) >= time_to_eat)
			break ;
		usleep(10);
	}
}

void	sleeping(t_info *info)
{
	long long current_time;
	long long start_sleep_time;
	long long time_to_sleep;

	time_to_sleep = (long long)info->time_to_sleep;
	start_sleep_time = get_time_ms();
	while (!info->die)
	{
		current_time = get_time_ms();
		if ((current_time - start_sleep_time) >= time_to_sleep)
			break ;
		usleep(10);
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->finish_mutex));
	pthread_mutex_lock(&(philo->info->eating_mutex));
	philo->last_eat_time = get_time_ms();
	print_mutex(*philo, "is eating");
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->info->eating_mutex));
	eating(philo->info);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&(philo->info->finish_mutex));
}

int	philo_do(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_mutex(*philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_mutex(*philo, "has taken a fork");
	eat(philo);

	if (philo->info->eat_check)
		return (-1);
	return (0);
}

void	*ft_philo(void *philo)
{
	t_info *info;
	t_philo *philo_copy;
	
	philo_copy = (t_philo *)philo;
	info = philo_copy->info;
	if (philo_copy->name % 2)
		usleep(1000 * info->time_to_eat);
	while (!info->die)
	{
		if (philo_do(philo_copy))
			break ;
		print_mutex(*philo_copy, "is sleeping");
		sleeping(info);
		print_mutex(*philo_copy, "is thinking");
	}
	return (0);
}
