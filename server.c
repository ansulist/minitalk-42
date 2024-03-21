/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:48:50 by ansulist          #+#    #+#             */
/*   Updated: 2023/06/02 11:23:13 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// basically, signal handler is a function
// that is used for receiving the signal from
// the client
// the way it works is by doing reading bit by bit
static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	sig_handler(int signalnbr)
{
	static int	i;
	static char	c;

	if (signalnbr == SIGUSR1)
		c = (c << 1) | 1;
	else if (signalnbr == SIGUSR2)
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

// if the arguments is more than 1
// which is the program name
// it should be error
int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr("ERROR!\nFORMAT IS = ./SERVER\nTRY AGAIN\n");
		return (0);
	}
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
