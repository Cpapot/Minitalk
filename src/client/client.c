/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:34:48 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/10 18:05:34 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

void	convert_utf8(int c, int pid)
{
	int	divide;

	divide = 0b10000000;
	while (divide != 0)
	{
		usleep(100);
		if ((c & divide) != 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		divide >>= 1;
	}
}

void	handler(int sig, siginfo_t *info, void *rien)
{
	static int	i = 0;

	(void )sig;
	if (rien == NULL && info->si_pid != 0)
		rien = NULL;
	i++;
}

void	init_sign(void)
{
	struct sigaction	inf;

	inf.sa_sigaction = handler;
	sigemptyset(&inf.sa_mask);
	inf.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &inf, NULL);
}

void	convert_size(int c, int pid)
{
	int	divide;
	int	i;

	i = 1;
	divide = 0b1000000000000000000000000000000;
	while (divide != 0 && i < 32)
	{
		if ((c & divide) != 0)
		{
			kill(pid, SIGUSR2);
			ft_printf("1");
		}
		else
		{
			kill(pid, SIGUSR1);
			ft_printf("0");
		}
		i++;
		divide >>= 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	init_sign();
	pid = check_args(argc, argv);
	convert_size(ft_strlen(argv[2]), pid);
	while (argv[2][i])
	{
		convert_utf8(argv[2][i], pid);
		i++;
	}
}
