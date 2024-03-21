/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:48:56 by ansulist          #+#    #+#             */
/*   Updated: 2023/06/02 11:33:41 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

void	error_flag(const char *str, int flag)
{
	while (*str)
	{
		if (*str != 32)
		{
			write(1, "Error! Check the PID\n\n", 22);
			exit(1);
		}
		str++;
	}
	if (flag == -1)
	{
		write(1, "Error! Check the PID\n", 22);
		exit(1);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	realnb;
	int	minusorplus;

	i = 0;
	realnb = 0;
	minusorplus = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minusorplus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		realnb = (realnb * 10) + (str[i] - 48);
		i++;
	}
	return (minusorplus * realnb);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
