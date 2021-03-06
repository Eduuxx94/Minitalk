/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:09:32 by ede-alme          #+#    #+#             */
/*   Updated: 2022/06/24 19:55:24 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sighandler(int signum)
{
	static t_data	data;

	data.sig = signum == SIGUSR2;
	data.c = (data.sig << data.index++) | data.c;
	if (data.index == 8)
	{
		if (!data.c)
			write(1, "\n", 1);
		data.index = 0;
		write(1, &data.c, 1);
		data.c = 0;
	}
}

void	ft_exit(int signum)
{
	ft_printf("Caught signal '%d' (Ctrl + C), coming out...\n", signum);
	exit(1);
}

int	main(void)
{
	signal(SIGINT, ft_exit);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	ft_printf("pid_server : %i\n", getpid());
	write(1, "Waiting for signal...\n", 22);
	while (1)
		pause();
	return (0);
}
