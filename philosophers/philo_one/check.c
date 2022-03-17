/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:08:20 by yson              #+#    #+#             */
/*   Updated: 2022/03/17 16:51:39 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_eat_check(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (info->num_of_philo_must_eat != 0 && i < info->num_of_philo
		&& philo[i].eat_count > info->num_of_philo_must_eat)
		i++;
	if (i == info->num_of_philo)
		info->eat_check = 1;
}

void	philo_death_check(t_info *info, t_philo *philo)
{
	int i;


	while (!(info->eat_check))
	{
		i = 0;
		while ((i < info->num_of_philo) && (!(info->die)))
		{
			pthread_mutex_lock(&(info->finish_mutex));
			pthread_mutex_lock(&(info->eating_mutex));
			if ((get_time_ms() - philo[i].last_eat_time) > info->time_to_die)
			{
				print_mutex(*philo, "died");
				info->die = 1;
			}
			pthread_mutex_unlock(&(info->eating_mutex));
			pthread_mutex_unlock(&(info->finish_mutex));
			i++;
		}
		if (info->die)
			break ;
		ft_eat_check(info, info->philos);
	}
}