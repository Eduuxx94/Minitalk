/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:08:38 by ede-alme          #+#    #+#             */
/*   Updated: 2022/06/24 19:55:27 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

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

int	ft_strlen(char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
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

void	action(int sig)
{
	static int	received;

	if (sig == SIGUSR1)
		received++;
	if (sig == SIGUSR2)
	{
		ft_printf("Bytes read by server -> %i\n", received);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_printf("You should put PID as argument and 'text'\n");
	else
	{
		pid = atoi(argv[argc - 2]);
		ft_printf("Bytes sent to server -> %i\n", ft_strlen(argv[argc - 1]));
		signal(SIGUSR1, action);
		signal(SIGUSR2, action);
		client(argv[argc - 1], pid);
		pause();
	}
	return (0);
}
