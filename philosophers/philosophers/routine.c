/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:07:55 by yson              #+#    #+#             */
/*   Updated: 2022/03/18 22:31:52 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	print_mutex(philo, "has taken a fork");
	pthread_mutex_lock(philo->left);
	print_mutex(philo, "has taken a fork");
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->check);		//check
	gettimeofday(&philo->last_time_to_eat, NULL);
	pthread_mutex_lock(&philo->info->finish_mutex);		//finish mutex
	if (!philo->info->finish)
		print_mutex(philo, "is eating");
	philo->eat_amount += 1;
	if (philo->eat_amount == philo->info->num_of_must_eat)
		philo->info->num_of_must_eat += 1;
	pthread_mutex_unlock(&philo->info->finish_mutex);		//finish mutex
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(&philo->check);				//check
}

static void	sleeping(t_philo *philo)
{
	print_mutex(philo, "is sleeping");
	usleep(philo->info->time_to_sleep * 1000);
}

static void	thinking(t_philo *philo)
{
	print_mutex(philo, "is thinking");
}

void	*philo(void *argv)
{
	t_philo	*philo;

	philo = argv;
	if (philo->name % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (!philo->info->finish)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
