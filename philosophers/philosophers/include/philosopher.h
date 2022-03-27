/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:42:29 by yson              #+#    #+#             */
/*   Updated: 2022/03/27 11:08:27 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>

typedef struct s_philo
{
	int				name;
	int				eat_amount;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		thread;
	struct s_info	*info;
	long long		last_time_to_eat;
}	t_philo;

typedef struct s_info
{
	int				finish;
	int				num_of_philo;
	int				eat_amount_goal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	long long		start_time;
	t_philo			*philos;
}	t_info;

int			ft_atoi_ad(char *str);
int			init(int argc, char **argv, t_info *info);

void		*philo(void *data);
void		*check_goal(void *data);
void		*monitor(void *data);

void		print_mutex(t_philo *philo, char *str);
long long	get_time_ms(void);
void		ft_usleep(int n);
void		error_exit(void);
#endif