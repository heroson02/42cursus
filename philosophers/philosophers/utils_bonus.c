/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:46:06 by yson              #+#    #+#             */
/*   Updated: 2022/03/27 13:27:59 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosopher_bonus.h"

int	malloc_arr(t_info *info)
{
	info->philos = malloc(sizeof(t_philo) * info->num_of_philo);
	if (!info->philos)
		return (0);
	memset(info->philos, 0, sizeof(t_philo) * info->num_of_philo);
	return (1);
}

void	error_exit(void)
{
	printf("Error Occured\n");
	exit(1);
}

long long	get_time_ms(void)
{
	struct timeval	time;
	int				val;

	val = gettimeofday(&time, 0);
	if (val == -1)
		error_exit();
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_mutex(t_philo *philo, char *str)
{
	sem_wait(philo->info->print_sem);
	printf("%lld\t%d\t%s\n", get_time_ms() - philo->info->start_time, \
		philo->name + 1, str);
	sem_post(philo->info->print_sem);
}
