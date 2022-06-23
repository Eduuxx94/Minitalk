/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:09:32 by ede-alme          #+#    #+#             */
/*   Updated: 2022/06/22 16:10:28 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void	sighandler(int signum)
{
	static char	c;
	static int	index;
	int			sig;

	sig = signum == SIGUSR2;
	c = (sig << index++) | c;
	if (index == 8)
	{
		write(1, &c, 1);
		index = 0;
		c = 0;
	}
}

void	ft_exit(int signum)
{
	printf("Caught signal '%d' (Ctrl + C), coming out...\n", signum);
	exit(1);
}

int	main(void)
{
	signal(SIGINT, ft_exit);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	printf("pid_server : %i\n", getpid());
	while (1)
		pause();
	return (0);
}
