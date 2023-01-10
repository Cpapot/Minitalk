/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:33:11 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/10 18:11:46 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

void	read_bin(int i, int sig, char **strp)
{
	static int				bin = 0;
	static unsigned int		u = 0;
	char					*str;

	str = *strp;
	if (i == 33)
		u = 0;
	if (sig != SIGUSR1VAR)
	{
		if ((i + 1) % 8 != 0)
			bin += ft_recursive_power(10, (8 - ((i + 1) % 8)));
		else
			bin += 1;
	}
	if ((i + 1) % 8 == 0)
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
	usleep(50);
	kill(info->si_pid, SIGUSR1);
	if (i <= 32)
		size = read_size(sig);
	else
	{
		if (i == 33)
		{
			str = malloc(sizeof(char) * (size + 1));
			if (str == NULL)
				return ;
		}
		read_bin(i, sig, &str);
		if (ft_strlen(str) == size)
		{
			ft_printf("%s", str);
			free(str);
			i = 0;
		}
	}
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
	}
}
