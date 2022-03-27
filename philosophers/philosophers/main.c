/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:25:54 by yson              #+#    #+#             */
/*   Updated: 2022/03/27 11:11:27 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosopher.h"

void	create_philos(t_info *info)
{
	int			i;
	pthread_t	thread;

	info->start_time = get_time_ms();
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philos[i].last_time_to_eat = info->start_time;
		if (pthread_create(&info->philos[i].thread, \
			NULL, philo, &info->philos[i]))
			error_exit();
		if (pthread_detach(info->philos[i].thread))
			error_exit();
	}
	if (pthread_create(&thread, NULL, monitor, info))
		error_exit();
	if (pthread_detach(thread))
		error_exit();
	if (info->num_of_must_eat != 0)
	{
		if (pthread_create(&thread, NULL, check_goal, info))
			error_exit();
		if (pthread_detach(thread))
			error_exit();
	}
}

void	end_philos(t_info *info)
{
	int		i;

	i = 0;
	pthread_mutex_lock(&info->finish_mutex);
	pthread_mutex_unlock(&info->finish_mutex);
	while (i < info->num_of_philo)
		pthread_mutex_destroy(&info->forks[i++]);
	pthread_mutex_unlock(&info->death_mutex);
	pthread_mutex_destroy(&info->finish_mutex);
	pthread_mutex_destroy(&info->death_mutex);
	pthread_mutex_destroy(&info->print_mutex);
	free(info->philos);
	free(info->forks);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!init(argc, argv, &info))
		error_exit();
	create_philos(&info);
	end_philos(&info);
}
