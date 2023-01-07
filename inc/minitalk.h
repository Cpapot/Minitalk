/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:32:06 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/07 02:31:59 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <signal.h>
# include "../libft/includes/libft.h"

# ifdef __linux__
#  define SIGUSR1VAR	30
#  define SIGUSR2VAR	31
# elif __APPLE__
#  define SIGUSR1VAR	10
#  define SIGUSR2VAR	12
# endif

/*						Client						*/
/*					check_error				*/
int	check_args(int argc, char **argv);

/*					Server							*/
#endif
