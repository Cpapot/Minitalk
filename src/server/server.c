/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:33:11 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/05 18:47:34 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

void	handler(int sig)
{
	ft_printf("Signal %d recu.\n", sig);
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
