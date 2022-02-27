/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yson <yson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:04:25 by yson              #+#    #+#             */
/*   Updated: 2021/09/25 21:03:14 by yson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	print_msg(char *msg, int *end, int *pid)
{
	if (*end)
	{
		if (!*msg)
		{
			if (kill(*pid, SIGUSR1) != 0)
			{
				write(1, "Error occured.\n", 15);
				exit(1);
			}
			*end = 0;
			*pid = 0;
		}
		else
			*pid = (*pid * 10) + (*msg - '0');
	}
	else
	{
		write(1, msg, 1);
		if (*msg == 0)
		{
			write(1, "\n", 1);
			*end = 1;
		}
	}
	*msg = 0;
}

void	handler(int signo, siginfo_t *info, void *context)
{
	static char	msg;
	static int	count;
	static int	pid;
	static int	end;

	(void)info;
	(void)context;
	if (--count == -1)
		count = 7;
	if (signo == SIGUSR1)
		msg |= (1 << count);
	else if (signo == SIGUSR2)
		msg &= ~(1 << count);
	if (count == 0)
		print_msg(&msg, &end, &pid);
}

int	main(void)
{
	int					pid;
	struct sigaction	s_sigact;

	s_sigact.sa_sigaction = handler;
	s_sigact.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "pid : ", 6);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &s_sigact, NULL) != 0)
	{
		write(1, "Wrong Signal\n", 13);
		exit(1);
	}
	if (sigaction(SIGUSR2, &s_sigact, NULL) != 0)
	{
		write(1, "Wrong Signal\n", 13);
		exit(1);
	}
	while (1)
		;
	return (0);
}
