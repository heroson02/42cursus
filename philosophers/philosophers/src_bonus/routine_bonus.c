/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:07:55 by yson              #+#    #+#             */
/*   Updated: 2022/03/22 18:19:46 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher_bonus.h"

void	pickup_fork(t_philo *philo)
{
	sem_wait(philo->info->forks);
	print_mutex(philo, "has taken a fork");
	sem_wait(philo->info->forks);
	print_mutex(philo, "has taken a fork");
}

void	eating(t_philo *philo)
{
	sem_wait(philo->check);
	philo->last_time_to_eat = get_time_ms();
	print_mutex(philo, "is eating");
	philo->eat_amount += 1;
	if (philo->eat_amount == philo->info->num_of_must_eat)
		sem_post(philo->info->eat_amount_goal);
	usleep(philo->info->time_to_eat * 1000);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	sem_post(philo->check);
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

void	philo(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, monitor, philo);
	if (philo->name % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (1)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	exit(0);
}
