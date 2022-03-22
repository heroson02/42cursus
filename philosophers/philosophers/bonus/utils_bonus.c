/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:46:06 by yson              #+#    #+#             */
/*   Updated: 2022/03/22 15:38:34 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void		error_exit()
{
	printf("Error Occured\n");
	exit(1);
}

long long   get_time_ms()
{
    struct timeval time;

    gettimeofday(&time, 0);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void    print_mutex(t_philo *philo, char *str)
{
    sem_wait(philo->info->print_sem);
	printf("%lld\t", get_time_ms() - philo->info->start_time);
	printf("%d\t", philo->name + 1);
	printf("%s\n", str);
    sem_post(philo->info->print_sem);
}
