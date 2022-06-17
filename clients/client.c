/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:08:38 by ede-alme          #+#    #+#             */
/*   Updated: 2022/06/17 21:41:26 by ede-alme         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		printf("You should put PID as argument and text\n");
	else
	{
		pid = atoi(argv[argc - 2]);
		printf("Arg PID -> %i\n", pid);
	}
	return (0);
}
