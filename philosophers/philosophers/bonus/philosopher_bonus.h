/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:42:29 by yson              #+#    #+#             */
/*   Updated: 2022/03/20 17:25:49 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				name;
	char			*sem_name;
	int				eat_amount;
	sem_t			*check;
	pthread_t		thread;
	struct s_info	*info;
	long long		last_time_to_eat;
}	t_philo;

typedef struct s_info
{
	int				finish;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				eat_amount_goal;
	sem_t			*forks;
	sem_t			*finish_sem;
	sem_t			*routine_sem;
	sem_t			print_sem;
	long long		start_time;
	t_philo			*philos;
}	t_info;

int	ft_atoi_ad(char *str);
int init(int argc, char **argv, t_info *info);

void	*philo(void *data);
void	*check_goal(void *data);
void	*monitor(void *data);

void    print_mutex(t_philo *philo, char *str);
long long   get_time_ms();
char	*ft_itoa(int n);
#endif