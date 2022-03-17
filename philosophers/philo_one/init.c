/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:06:33 by yson              #+#    #+#             */
/*   Updated: 2022/03/17 16:51:13 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int check_input_arg(int argc, char **argv, t_info *info)
{
	if (argc != 5 && argc != 6)
		return (0);
	info->num_of_philo = ft_atoi_ad(argv[1]);
	info->time_to_die = ft_atoi_ad(argv[2]);
	info->time_to_eat = ft_atoi_ad(argv[3]);
	info->time_to_die = ft_atoi_ad(argv[4]);
	info->num_of_philo_must_eat = 0;
	info->die = 0;
	info->eat_check = 0;
	info->time_start = 0;
	if (argv[5])
	{
		info->num_of_philo_must_eat = ft_atoi_ad(argv[5]);
		if (info->num_of_philo_must_eat < 1)
			return (0);
	}
	if (info->num_of_philo < 0 || info->time_to_die < 0
		|| info->time_to_eat < 0 || info->time_to_sleep < 0)
		return (0);
	return (1);
}

int	malloc_info(t_info *info)
{
	info->forks_mutex = malloc((info->num_of_philo) * sizeof(pthread_mutex_t));
	info->philos = malloc((info->num_of_philo) * sizeof(t_philo));
	if (!info->forks_mutex || !info->philos)
		return (0);
	return (1);
}

int mutex_init(t_info *info)
{
	int i;

	i = 0;
	if (pthread_mutex_init(&info->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&info->eating_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&info->finish_mutex, NULL) != 0)
		return (0);
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_init(&info->forks_mutex[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	philo_init(t_info *info)
{
	int i;

	i = 0;	
	while (i < info->num_of_philo)
	{
		info->philos[i].name = i;
		info->philos[i].eat_count = 0;
		info->philos[i].last_eat_time = 0;
		info->philos[i].info = info;
		info->philos[i].left_fork = &(info->forks_mutex[i]);
		if (i + 1 == info->num_of_philo)
			info->philos[i].right_fork = &(info->forks_mutex[0]);
		else
			info->philos[i].right_fork = &(info->forks_mutex[i + 1]);
		i++;
	}
	return (1);
}

int	init_info(int argc, char **argv, t_info *info)
{
	if (!check_input_arg(argc, argv, info))
		return (0);
	if (!malloc_info(info))
		return (0);
	if (!mutex_init(info))
		return (0);
	if (!philo_init(info))
		return (0);
	return (1);
}
