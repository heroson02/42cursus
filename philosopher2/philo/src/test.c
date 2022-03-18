#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	check(t_info *info)
{
	int i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		pthread_mutex_init(&info->philos[i].check_mutex, NULL);
		i++;
	}
	
}

static int	is_contain(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static unsigned long long	ft_atois(char *str)
{
	int					i;
	int					minus;
	unsigned long long	result;
	unsigned long long	base_len;

	result = 0;
	minus = 1;
	i = 0;
	base_len = 10;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			exit(0);
		if (is_contain("0123456789", str[i]) != -1)
			result = result * base_len + (is_contain("0123456789", str[i++]));
	}
	return (result * minus);
}

int	ft_atoi_ad(char *str)
{
	long long	num;

	num = ft_atois(str);
	if (num > 2147483647 || num < -2147483648)
		exit(0);
	return ((int)num);
}

// ///////////////////////////////////////////////////////

int	arg_range_check(t_info *info, int argc)	//문제 x
{
	if (info->num_of_must_eat < 1 && argc == 6)
		return (0);
	if (info->num_of_must_eat < 0 || info->time_to_die < 0 \
		|| info->time_to_eat < 0 || info->time_to_sleep < 0)
		return (0);
	return (1);
}

int	handle_arg(int argc, char **argv, t_info *info)	//문제 x
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

int malloc_arr(t_info *info)
{
	// info->philos = malloc(sizeof(t_philo) * info->num_of_philo);
	// if (!info->philos)
	// 	return (0);
	// memset(info->philos, 0, sizeof(t_philo) * info->num_of_philo);
	// info->forks = malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	// if (!info->forks)
	// 	return (0);
	// memset(info->forks, 0, sizeof(pthread_mutex_t) * info->num_of_philo);
	// return (1);
	ft_malloc(&info->philos, sizeof(t_philo) * info->num_of_philo);
	ft_malloc(&info->forks ,sizeof(pthread_mutex_t) * info->num_of_philo);
	return (1);
}

int	init_philos(t_info *info)
{
	int i;

	i = 0;
	if (!malloc_arr(info))
		return (0);
	if (pthread_mutex_init(&info->finish_mutex, NULL))
		return (0);
	while (i < info->num_of_philo)
	{
		info->philos[i].n = i;
		info->philos[i].info = info;
		if (pthread_mutex_init(&info->philos[i].check_mutex, NULL))
			return (0);
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (0);
		// if (i == 0)
		// 	info->philos[i].left = &info->forks[info->num_of_philo - 1];
		// else
		// 	info->philos[i].left = &info->forks[i - 1];
		// info->philos[i].right = &info->forks[i];
		info->philos[i].left = &info->forks[i];
		if (i + 1 == info->num_of_philo)
			info->philos[i].right = &info->forks[0];
		else
			info->philos[i].right = &info->forks[i + 1];
		i++;
	}
	return (1);
}

int	init(t_info *info, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (FT_ERROR);
	if (!handle_arg(argc, argv, info))
		return (FT_ERROR);
	if (!init_philos(info))
		return (FT_ERROR);
	return (FT_SUCCESS);
}