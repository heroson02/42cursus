/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:19:55 by yson              #+#    #+#             */
/*   Updated: 2022/03/16 19:30:35 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_info
{
	int 			die;
	int				num_of_philo;
	int 			time_to_die;
	int 			time_to_eat;
	int				time_to_sleep;
	int				num_of_philo_must_eat;
	long long		time_start;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t print_mutex;
	
	struct s_philo	*philos;
}	t_info;

typedef struct s_philo
{
	int				name;
	long long		last_eat_time;
	int				eat_count;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread_id;
	t_info			*info;
}	t_philo;

int		ft_atoi_ad(char *str);
void	error_exit(void);
long long	get_time_ms(void);
void	print_mutex(t_philo philo, char *str);

#endif