/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:44:42 by yson              #+#    #+#             */
/*   Updated: 2022/03/18 17:24:51 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	arg_range_check(t_info *info, int argc)
{
	if (info->num_of_must_eat < 1 && argc == 6)
		return (0);
	if (info->num_of_must_eat < 0 || info->time_to_die < 0 \
		|| info->time_to_eat < 0 || info->time_to_sleep < 0)
		return (0);
	return (1);
}

int	handle_arg(int argc, char **argv, t_info *info)
{
	memset(info, 0, sizeof(t_info));
	info->num_of_philo = ft_atoi_ad(argv[1]);
	info->time_to_die = ft_atoi_ad(argv[2]);
	info->time_to_eat = ft_atoi_ad(argv[3]);
	info->time_to_sleep = ft_atoi_ad(argv[4]);
	if (argc == 6)
		info->num_of_must_eat = ft_atoi_ad(argv[5]);
	if (!arg_range_check(info, argc))
		return (0);
	return (1);
}

int malloc_arr(t_info *info)
{
	info->philos = malloc(sizeof(t_philo) * info->num_of_philo);
	if (!info->philos)
		return (0);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->forks)
		return (0);
	return (1);
}

int	init_philos(t_info *info)
{
	int i;

	i = 0;
	if (!malloc_arr(info))
		return (0);
	if (pthread_mutex_init(&info->finish_mutex, NULL))
		return (0);
	while (i < info->num_of_philo)
	{
		info->philos->name = i;
		info->philos->info = info;
		if (pthread_mutex_init(&info->philos[i].check, NULL))
			return (0);
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (0);
		// if (i == 0)
		// 	info->philos[i].left = &info->forks[info->num_of_philo - 1];
		// else
		// 	info->philos[i].left = &info->forks[i - 1];
		// info->philos[i].right = &info->forks[i];
		info->philos[i].left = &info->forks[i];
		if (i + 1 == info->num_of_philo)
			info->philos[i].right = &info->forks[0];
		else
			info->philos[i].right = &info->forks[i + 1];
		i++;
	}
	
}

int init(int argc, char **argv, t_info *info)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (!handle_arg(argc, argv, info))
		return (0);
	if (!init_philos(info))
		return (0);
	return (1);
}
