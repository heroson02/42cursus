/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:19:55 by yson              #+#    #+#             */
/*   Updated: 2022/03/09 23:41:58 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_info
{
	int 			alive;
	int				num_of_philo;
	int 			time_to_die;
	int 			time_to_eat;
	int				time_to_sleep;
	int				num_of_philo_must_eat;
	long long		time_start;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t print_mutex;
	
	t_philo	*philos;
}	t_info;

typedef struct s_philo
{
	int				name;
	int				last_eat_time;
	int				eat_count;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	t_info			*info;
}	t_philo;

int		ft_atoi_ad(char *str);
void	error_exit(void);

#endif