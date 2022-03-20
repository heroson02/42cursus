/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:44:42 by yson              #+#    #+#             */
/*   Updated: 2022/03/20 17:27:22 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

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

int	ft_malloc(void *target, size_t size)
{
	*(void **)target = malloc(size);
	if (*(void **)target == 0)
		return (0);
	memset(*(void **)target, 0, size);
	return (1);
}

int malloc_arr(t_info *info)
{
	if (!ft_malloc(&info->philos, sizeof(t_philo) * info->num_of_philo) ||
		!ft_malloc(&info->forks ,sizeof(pthread_mutex_t) * info->num_of_philo))
		return (0);
	return (1);
}

sem_t	*init_sem(char *name, unsigned int num)
{
	sem_t *result;

	result = sem_open(name, O_CREAT | O_EXCL, 0644, num);
	if (result != SEM_FAILED)
		return (result);
	sem_unlink(name);
	exit(0); //에러를 이렇게 처리하는게 맞는지 체크하기
	// return (sem_open(name, O_CREAT | O_EXCL, 0644, num));
}

int	init_philos(t_info *info)
{
	int i;

	i = 0;
	if (!malloc_arr(info))
		return (0);
	info->finish_sem = init_sem("finish_sem", 0);
	info->print_sem = init_sem("print_sem", 1);
	info->routine_sem = init_sem("routine_sem", 1);
	info->forks = init_sem("forks", info->num_of_philo + 1);
	while (i < info->num_of_philo)
	{
		info->philos[i].name = i;
		info->philos[i].sem_name = ft_itoa(i + 1);
		info->philos[i].info = info;
		info->philos[i].check = init_sem(info->philos[i].sem_name, 1);
		i++;
	}
	return (1);
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