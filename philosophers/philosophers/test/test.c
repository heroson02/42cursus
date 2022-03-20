#include "../bonus/philosopher_bonus.h"
#include <signal.h>
typedef struct s_test
{
	pid_t	current;
}	t_test;

int main()
{
	sem_t	*forks;
	int		num_of_philo;
	t_test *philos;

	num_of_philo = 5;
	printf("%d\n", getpid());
	philos = malloc(sizeof(t_test) * num_of_philo);
	forks = sem_open("forks", O_CREAT, S_IRWXU, 1);
	for (int i = 1; i < num_of_philo; i++)
	{
		philos[i].current = fork();
		if (philos[i].current == 0)
		{
			printf("hello\n");
			return (0);
		}
	}
	printf("%d\n", getpid());
}
