/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:34:48 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/07 02:18:42 by cpapot           ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	pid = check_args(argc, argv);
	while (argv[2][i])
	{
		convert_utf8(argv[2][i], pid);
		i++;
	}
}
