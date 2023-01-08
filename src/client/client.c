/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:34:48 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/08 16:46:27 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

void	convert_utf8(char c, int pid)
{
	int	divide;

	divide = 0b10000000;
	while (divide != 0)
	{
		if ((c & divide) != 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		divide >>= 1;
		usleep(25);
	}
	pause();
}

void	handler(int sig, siginfo_t *info, void *rien)
{
	(void )sig;
	if (rien == NULL)
		rien = NULL;
	ft_printf("ok %d", info->si_pid);
}

void	init_sign(void)
{
	struct sigaction	inf;

	inf.sa_sigaction = handler;
	sigemptyset(&inf.sa_mask);
	inf.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &inf, NULL);
	sigaction(SIGUSR2, &inf, NULL);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	init_sign();
	pid = check_args(argc, argv);
	while (argv[2][i])
	{
		convert_utf8(argv[2][i], pid);
		i++;
	}
}
