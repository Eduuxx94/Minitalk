/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:08:38 by ede-alme          #+#    #+#             */
/*   Updated: 2022/06/24 19:55:29 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	signal;

	signal = 0;
	number = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signal = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + ((int) *str - 48);
		str++;
	}
	if (signal == -1)
		return (signal * number);
	return (number);
}

void	client(char *str, int pid)
{
	int		index;
	char	c;

	if (!str)
		return ;
	while (1)
	{
		index = 0;
		c = *str;
		while (index < 8)
		{
			if (c >> index & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			index++;
		}
		if (*str == 0)
			break ;
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = atoi(argv[argc - 2]);
	if (argc != 3)
		ft_printf("You should put PID as argument and 'text'\n");
	else
		client(argv[argc - 1], pid);
	return (0);
}
