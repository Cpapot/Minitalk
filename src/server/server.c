/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:33:11 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/06 18:30:45 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

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

	if (sig != 30)
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
	struct sigaction	test;

	test.sa_handler = handler;
	sigemptyset(&test.sa_mask);
	test.sa_flags = SA_RESTART;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &test, NULL);
	sigaction(SIGUSR2, &test, NULL);
	while (1)
	{
		pause();
	}
}
