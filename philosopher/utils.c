/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:04:37 by yson              #+#    #+#             */
/*   Updated: 2022/03/16 19:32:25 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	get_time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec / 1000 + tv.tv_sec * 1000);
}

void	print_mutex(t_philo philo, char *str)
{
	pthread_mutex_lock(&philo.info->print_mutex);
	if (!philo.info->die)
		printf("%lld %d %s\n", get_time_ms() - philo.info->time_start, philo.name + 1,str);
	pthread_mutex_unlock(&philo.info->print_mutex);
}
