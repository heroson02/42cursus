/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:04:14 by yson              #+#    #+#             */
/*   Updated: 2021/09/25 21:05:03 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	send_msg(int pid, char msg)
{
	int	mask;

	mask = 128;
	while (mask)
	{
		if (msg & mask)
		{
			if (kill(pid, SIGUSR1) != 0)
			{
				write(1, "PID Error\n", 10);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) != 0)
			{
				write(1, "PID Error\n", 10);
				exit(1);
			}
		}
		mask >>= 1;
		usleep(50);
	}
}

void	send_pid(int dest_PID, int source_PID)
{
	char	*pid;
	int		i;

	i = 0;
	pid = ft_itoa(source_PID);
	while (pid[i])
	{
		send_msg(dest_PID, pid[i]);
		i++;
	}
	free(pid);
}

void	success(int signo)
{
	(void)signo;
	write(1, "Message sent successfully!\n", 27);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3)
	{
		write(1, "Parameter Error\n", 16);
		return (0);
	}
	msg = argv[2];
	pid = ft_atoi(argv[1]);
	if (!((pid >= 100) && (pid < 100000)))
		return (0);
	signal(SIGUSR1, success);
	while (*msg)
	{
		send_msg(pid, *msg);
		msg++;
	}
	send_msg(pid, '\0');
	send_pid(pid, getpid());
	send_msg(pid, '\0');
	return (0);
}
