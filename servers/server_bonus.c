/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:09:32 by ede-alme          #+#    #+#             */
/*   Updated: 2022/06/24 19:54:59 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	sighandler(int signum, siginfo_t *info, void *context)
{
	static t_data	data;

	(void)context;
	data.sig = signum == SIGUSR2;
	data.c = (data.sig << data.index++) | data.c;
	if (data.index == 8)
	{
		data.index = 0;
		if (!data.c)
		{
			write(1, "\n", 1);
			write(1, "Waiting for signal...\n", 22);
			kill(info->si_pid, SIGUSR2);
		}
		else
			kill(info->si_pid, SIGUSR1);
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
	struct sigaction	s_info;

	s_info.sa_sigaction = sighandler;
	s_info.sa_flags = SA_SIGINFO;
	signal(SIGINT, ft_exit);
	sigaction(SIGUSR1, &s_info, 0);
	sigaction(SIGUSR2, &s_info, 0);
	ft_printf("pid_server : %i\n", getpid());
	write(1, "Waiting for signal...\n", 22);
	while (1)
		pause();
	return (0);
}
