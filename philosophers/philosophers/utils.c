/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:46:06 by yson              #+#    #+#             */
/*   Updated: 2022/03/23 12:27:24 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosopher.h"

void	error_exit(void)
{
	printf("Error Occured\n");
	exit(1);
}

void	ft_usleep(int n)
{
	int	val;

	val = usleep(n);
	if (val)
		error_exit();
}

long long	get_time_ms(void)
{
	struct timeval	time;
	int				val;

	val = gettimeofday(&time, 0);
	if (val)
		error_exit();
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_mutex(t_philo *philo, char *str)
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
