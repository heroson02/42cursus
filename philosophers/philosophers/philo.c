/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:06:14 by yson              #+#    #+#             */
/*   Updated: 2022/03/18 23:43:50 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long   get_time_ms()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void    print_mutex(t_philo *philo, char *str)
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

void	join_and_free_philos(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->philos[i].thread, NULL);
		pthread_mutex_destroy(&info->philos[i++].check);
	}
	free(info->philos);
	i = 0;
	while (i < info->num_of_philo)
		pthread_mutex_destroy(&info->forks[i++]);
	free(info->forks);
}

void	create_philos(t_info *info)
{
	int			i;
	pthread_t	thread;

	info->start_time = get_time_ms();
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].last_time_to_eat = info->start_time;
		pthread_create(&info->philos[i].thread, NULL, philo, &info->philos[i]);
		pthread_create(&thread, NULL, monitor, &info->philos[i]);
		pthread_detach(thread);
		++i;
	}
	if (info->num_of_must_eat != 0)
	{
		pthread_create(&thread, NULL, check_goal, info);
		pthread_detach(thread);
	}
}