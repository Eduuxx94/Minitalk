/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:09:32 by ede-alme          #+#    #+#             */
/*   Updated: 2022/06/17 21:57:35 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("ID from server: -> %d\n", pid);
	while (1)
	{
		pause();
	}
}
