/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:33:11 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/12 23:49:30 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

void	send_info(int pid)
{
	usleep(7);
	if (kill(pid, SIGUSR1) == -1)
	{
		ft_putstr_fd("SIGUSR1 error\n", 2);
		usleep(10);
		kill(pid, SIGUSR2);
		exit(EXIT_FAILURE);
	}
}

void	read_bin(int i, int sig, char **strp)
{
	static int				bin = 0;
	static unsigned int		u = 0;
	char					*str;

	str = *strp;
	if (i == 33)
	{
		u = 0;
		bin = 0;
	}
	if (sig != SIGUSR1VAR)
	{
		if (i % 8 != 0)
			bin += ft_recursive_power(10, (8 - (i % 8)));
		else
			bin += 1;
	}
	if (i % 8 == 0)
	{
		str[u] = bin_to_dec(bin);
		str[u + 1] = '\0';
		u++;
		bin = 0;
	}
}

void	handler(int sig, siginfo_t *info, void *rien)
{
	static int				i = 0;
	static unsigned int		size;
	static char				*str;

	i++;

	if (rien != NULL)
		rien = NULL;
	if (i <= 32)
		size = read_size(sig, i);
	else
	{
		if (i == 33)
		{
			str = malloc(sizeof(char) * (size + 1));
			if (str == NULL)
				return ;
		}
		read_bin(i, sig, &str);
		//ft_printf("i: (%d), size : (%u), (i - 32) / 8 : (%i)\n", i, size, (i - 32) / 8);
		if (((unsigned int)i - 32) / 8 == size)
		{
			ft_printf("%s\n", str);
			free(str);
			i = 0;
		}
	}
	send_info(info->si_pid);
}

int	main(void)
{
	struct sigaction	inf;

	inf.sa_sigaction = handler;
	sigemptyset(&inf.sa_mask);
	inf.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &inf, NULL);
	sigaction(SIGUSR2, &inf, NULL);
	while (1)
	{
		pause();
	}
}
