/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:07:55 by yson              #+#    #+#             */
/*   Updated: 2022/03/22 18:39:26 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosopher.h"

void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	print_mutex(philo, "has taken a fork");
	pthread_mutex_lock(philo->left);
	print_mutex(philo, "has taken a fork");
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->check);
	philo->last_time_to_eat = get_time_ms();
	pthread_mutex_lock(&philo->info->finish_mutex);
	if (!philo->info->finish)
		print_mutex(philo, "is eating");
	philo->eat_amount += 1;
	if (philo->eat_amount == philo->info->num_of_must_eat)
		philo->info->eat_amount_goal += 1;
	pthread_mutex_unlock(&philo->info->finish_mutex);
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(&philo->check);
}

void	sleeping(t_philo *philo)
{
	print_mutex(philo, "is sleeping");
	usleep(philo->info->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	print_mutex(philo, "is thinking");
}

void	*philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->name % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (!philo->info->finish)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}
