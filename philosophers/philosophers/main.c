/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:25:54 by yson              #+#    #+#             */
/*   Updated: 2022/03/24 11:59:45 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosopher.h"

void	create_philos(t_info *info)
{
	int			i;
	pthread_t	thread;

	info->start_time = get_time_ms();
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].last_time_to_eat = info->start_time;
		if (pthread_create(&info->philos[i].thread, \
			NULL, philo, &info->philos[i]))
			error_exit();
		if (pthread_create(&thread, NULL, monitor, &info->philos[i]))
			error_exit();
		if (pthread_detach(thread))
			error_exit();
		++i;
	}
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
	while (i < info->num_of_philo)
	{
		if (pthread_join(info->philos[i].thread, NULL))
			error_exit();
		if (pthread_mutex_destroy(&info->philos[i++].check))
			error_exit();
	}
	free(info->philos);
	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_destroy(&info->forks[i++]))
			error_exit();
	}
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
