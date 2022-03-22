/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:25:54 by yson              #+#    #+#             */
/*   Updated: 2022/03/22 17:58:55 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	create_philos(t_info *info)
{
	int			i;

	info->start_time = get_time_ms();
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].last_time_to_eat = info->start_time;
		info->philos[i].pid = fork();
		if (info->philos[i].pid == 0)
			return (philo(&info->philos[i]));
		else if (info->philos[i].pid < 0)
			error_exit();
		++i;
	}
}

void	end_philos(t_info *info)
{
	int		i;
	int		statloc;

	i = 0;
	while (i < info->num_of_philo)
	{
		waitpid(info->philos[i].pid, &statloc, 0);
		sem_close(info->philos[i].check);
		free(info->philos[i].sem_name);
		i++;
	}
	free(info->philos);
	sem_close(info->forks);
	sem_close(info->finish_sem);
	sem_close(info->print_sem);
	sem_close(info->eat_amount_goal);
}

int	main(int argc, char **argv)
{
	t_info		info;
	pthread_t	thread;

	if (!init(argc, argv, &info))
		return (0);
	create_philos(&info);
	if (info.num_of_must_eat != 0)
		pthread_create(&thread, NULL, check_goal, &info);
	pthread_create(&thread, NULL, finish_check, &info);
	end_philos(&info);
}
