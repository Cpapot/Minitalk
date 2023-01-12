/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:52 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/12 23:25:09 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

int	bin_to_dec(unsigned long long bin)
{
	int				i;
	int				digit;
	unsigned int	dec;

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

int	ft_recursive_power(unsigned long int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

unsigned int	read_size(int sig, int i)
{
	static unsigned long long int	bin = 0;
	unsigned long long int			tmp;

	if (sig != SIGUSR1VAR)
	{
		if (i % 32 != 0)
			bin += ft_recursive_power(10, (32 - i));
		else
			bin += 1;
	}
	if (i % 32 == 0)
	{
		tmp = bin;
		bin = 0;
		return (bin_to_dec(tmp));
	}
	return (0);
}
