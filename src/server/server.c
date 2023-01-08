/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:33:11 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/08 16:27:19 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

struct sigaction	inf;

void gestionnaire(int num_sig, siginfo_t *info, void *rien)
{
	(void)num_sig;
	if (rien != NULL)
		rien = NULL;
	ft_printf("J'ai recu un signal du pid : %d\n",info->si_pid);
}
/*
void	send_receipt(int bin)
{
	if (bin == 0)
		kill(, SIGUSR1);
	else
		kill(,SIGUSR2)
}
*/
int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int	bin_to_dec(int bin)
{
	int	i;
	int	digit;
	int	dec;

	dec = 0;
	i = 0;
	while (bin != 0)
	{
		digit = bin % 10;
		dec += digit << i;
		bin = bin / 10;
		i++;
	}
	return (dec);
}

void	handler(int sig)
{
	static int	bin = 0;
	static int	i = 1;

	if (sig != 10)
	{
		if (i % 8 != 0)
			bin += ft_recursive_power(10, (8 - i));
		else
			bin += 1;
	}
	if (i % 8 == 0)
	{
		ft_printf("%c", bin_to_dec(bin));
		i = 0;
		bin = 0;
	}
	i++;
}

int	main(void)
{
	inf.sa_handler = handler;
	inf.sa_sigaction = gestionnaire;
	sigemptyset(&inf.sa_mask);
	inf.sa_flags = SA_RESTART;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &inf, NULL);
	sigaction(SIGUSR2, &inf, NULL);
	while (1)
	{
		pause();
	}
}

