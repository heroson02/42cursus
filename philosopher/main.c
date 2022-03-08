/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:19:29 by yson              #+#    #+#             */
/*   Updated: 2022/03/08 23:30:45 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_info(int argc, char **argv, t_info *info)
{
	if (argc != 6 || argc != 7)
	info->num_of_philo = ft_atoi_ad(argv[1]);
	info->time_to_die = ft_atoi_ad(argv[2]);
	info->time_to_eat = ft_atoi_ad(argv[3]);
	info->time_to_die = ft_atoi_ad(argv[4]);
	info->alive = 1;
	if (argv[5])
		info->num_of_philo_must_eat = ft_atoi_ad(argv[5]);
	else
		info->num_of_philo_must_eat = -1;
	if (info->num_of_philo < 0 || info->time_to_die < 0
		|| info->time_to_eat < 0 || info->time_to_sleep < 0)
		error_exit();
}

int	init_fork(t_info *info)
{
	info->forks_mutex = malloc((info->num_of_philo + 1) * sizeof(pthread_mutex_t));
	info->philos = malloc((info->num_of_philo + 1) * sizeof(t_philo));
	pthread_mutex_init(&info->print_mutex, NULL);
	if (!info->forks_mutex || !info->philos)
		return (0)
	
}

void	print_mutex(t_philo philo, char *str)
{
	pthread_mutex_lock(&philo.info->print_mutex);
	printf("%s\n", str);
	pthread_mutex_unlock(&philo.info->print_mutex);
}

void	ft_philosopher(t_info *info)
{
	
}

unsigned long long	get_time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec / 1000 + tv.tv_sec * 1000);
}

int main(int argc, char **argv)
{
	t_info info;

	init_info(argc, argv, &info);
	init_fork(info);
}
