/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:03:46 by ede-alme          #+#    #+#             */
/*   Updated: 2022/06/24 19:55:18 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
#include "../includes/ft_printf.h"

typedef struct s_data {
	char	c;
	int		index;
	int		sig;
}	t_data;

//Functions from server bellow:
void	sighandler(int signum);
void	ft_exit(int signum);

//Functions from client bellow:
int		ft_atoi(const char *str);
void	client(char *str, int pid);

#endif