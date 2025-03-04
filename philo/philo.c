/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:33:44 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 10:47:59 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_simulation(int ac, char **av)
{
	ac += 0;
	av += 0;
	return (0);
}

int	parse_arg(int ac, char **av)
{
	ac += 0;
	av += 0;
	return (0);
}

void	philo(int ac, char **av)
{
	int	error;

	error = validate_arg(ac, av);
	if (0 == error)
		error = parse_arg(ac, av);
	if (0 == error)
		error = do_simulation(ac, av);
	print_error(error);
}
