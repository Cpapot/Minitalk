/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:49:58 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/04 17:10:57 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

void	print_error(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

int	check_pid(char *chpid)
{
	int	i;
	int	pid;

	i = 0;
	while (chpid[i])
	{
		if (!ft_isdigit(chpid[i]))
			print_error("incorrect PID\n");
		i++;
	}
	pid = ft_atoi(chpid);
	if (kill(pid, 0) == -1)
		print_error("incorrect PID\n");
	return (pid);
}

void	check_args(int argc, char **argv)
{
	if (argc > 3)
		print_error("to many arguments\n");
	else if (argc < 3)
		print_error("to few arguments\n");
	check_pid(argv[1]);
	ft_printf("ok");
	(void)argv;
}
