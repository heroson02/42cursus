/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:06:39 by yson              #+#    #+#             */
/*   Updated: 2022/03/22 18:19:04 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher_bonus.h"

void	*finish_check(void *data)
{
	t_info	*info;
	int		i;

	info = (t_info *)data;
	i = -1;
	sem_wait(info->finish_sem);
	while (++i < info->num_of_philo)
		kill(info->philos[i].pid, SIGTERM);
	return (0);
}

void	*check_goal(void *data)
{
	t_info	*info;
	int		i;

	i = 0;
	info = (t_info *)data;
	while (i < info->num_of_philo)
	{
		sem_wait(info->eat_amount_goal);
		i++;
	}
	sem_post(info->finish_sem);
	return (0);
}

void	*monitor(void *data)
{
	t_philo			*philo;
	long long		ms;

	philo = (t_philo *)data;
	while (!philo->info->finish)
	{
		sem_wait(philo->check);
		sem_wait(philo->info->print_sem);
		ms = get_time_ms() - philo->last_time_to_eat;
		if (ms >= philo->info->time_to_die)
		{
			printf("%lld\t", get_time_ms() - philo->info->start_time);
			printf("%d\t", philo->name + 1);
			printf("%s\n", "died");
			sem_post(philo->info->finish_sem);
			return (0);
		}
		sem_post(philo->info->print_sem);
		sem_post(philo->check);
	}
	return (0);
}
