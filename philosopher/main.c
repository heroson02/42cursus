/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:19:29 by yson              #+#    #+#             */
/*   Updated: 2022/03/16 19:43:15 by yson             ###   ########.fr       */
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

void	eating(t_info *info)
{
	long long current_time;
	long long start_eat_time;
	long long time_to_eat;

	time_to_eat = info->time_to_eat;
	start_eat_time = get_time_ms();
	while (!info->die)
	{
		current_time = get_time_ms();
		if (current_time - start_eat_time >= time_to_eat)
			break ;
		usleep(100);
	}
}

void	sleeping(t_philo *philo)
{
	long long current_time;
	long long start_sleep_time;
	long long time_to_sleep;

	start_sleep_time = get_time_ms();
	time_to_sleep = philo->info->time_to_sleep;
	while (!philo->info->die)
	{
		current_time = get_time_ms();
		if (current_time - start_sleep_time >= time_to_sleep)
			break ;
		usleep(100);
	}
}

void	eat(t_philo *philo)
{
	print_mutex(*philo, "is eating");
	philo->last_eat_time = get_time_ms();
	eating(philo->info);
	philo->eat_count++;
}

int	philo_do(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_mutex(*philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_mutex(*philo, "has taken a fork");
	eat(philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

void	*ft_philo(void *philo)
{
	t_info *info;
	t_philo *philo_copy;
	
	philo_copy = (t_philo *)philo;
	info = philo_copy->info;
	if (philo_copy->name % 2)
		usleep(10000);
	while (!info->die)
	{
		if (philo_do(philo_copy))
			break ;
		print_mutex(*philo_copy, "is sleeping");
		sleeping(philo_copy);
		print_mutex(*philo_copy, "is thinking");
	}
	return (0);
}

int	start_philo(t_info *info, t_philo *philos)
{
	int		i;
	void	*v_philo;

	i = 0;
	info->time_start = get_time_ms();
	while (i < info->num_of_philo)
	{	
		philos[i].last_eat_time = get_time_ms();
		v_philo = (void *)&(philos[i]);
		if (pthread_create(&(philos[i].thread_id), NULL, ft_philo, v_philo))
			return (0);
		i++;
	}
	// ft_death_check(game, game->philo);
	// ft_end_philo(game, game->philo);
	return (1);
}

int main(int argc, char **argv)
{
	t_info info;

	if (!init_info(argc, argv, &info))
		error_exit();
	if (!start_philo(&info, (&info)->philos))
		error_exit();
}
