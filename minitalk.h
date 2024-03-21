/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:48:40 by ansulist          #+#    #+#             */
/*   Updated: 2023/06/02 11:22:08 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "unistd.h"

int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putnbr_fd(int n, int fd);
void	error_flag(const char *string, int flag);

#endif