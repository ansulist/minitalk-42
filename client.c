/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:48:32 by ansulist          #+#    #+#             */
/*   Updated: 2023/06/02 11:21:40 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(char c, int pid)
{
	int	i;

	i = 128;
	(void)pid;
	while (i > 0)
	{
		if ((c & i) == i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i = i / 2;
		usleep(150);
	}
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
	}
	else
		write(1, "Error! Format ./client <server_pid> <message>\n", 47);
}
