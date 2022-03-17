/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:19:29 by yson              #+#    #+#             */
/*   Updated: 2022/03/17 16:55:06 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_end(t_info *info, t_philo *philos)
{
	int i;

	i = 0;
	while (i < info->num_of_philo)
		pthread_join(philos[i++].thread_id, NULL);
	i = 0;
	while (i < info->num_of_philo)
		pthread_mutex_destroy(&info->forks_mutex[i++]);
	free(info->philos);
	free(info->forks_mutex);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eating_mutex);
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
	philo_death_check(info, info->philos);
	philo_end(info, philos);
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
