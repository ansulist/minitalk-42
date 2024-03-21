/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:48:25 by ansulist          #+#    #+#             */
/*   Updated: 2023/06/02 11:20:39 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

int	g_len;

void	received_message(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Received [", 11);
		ft_putnbr_fd(g_len, 1);
		write(1, "] characaters. \n", 17);
	}
	exit(1);
}

void	signal_handler(char c, int pid)
{
	int	i;
	int	j;

	i = 128;
	j = 0;
	(void)pid;
	while (i > 0)
	{
		if ((c & i) == i)
			j = kill(pid, SIGUSR1);
		else
			j = kill(pid, SIGUSR2);
		i = i / 2;
		usleep(150);
	}
	error_flag("", j);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
			signal_handler(av[2][i++], pid);
		signal_handler('\0', pid);
		g_len = i;
		signal(SIGUSR1, received_message);
		while (1)
			pause();
	}
	else
		write(1, "Error! Format ./client (server_pid) (message)\n", 47);
}
