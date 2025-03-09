/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:10:21 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 15:58:34 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_data(int ac, t_data *d)
{
	if (0 >= d->philo_count || MAX_PHILO_COUNT < d->philo_count)
		return (4);
	if (0 >= d->die_time || MIN_MSEC_VALUE > d->die_time)
		return (5);
	if (0 >= d->eat_time || MIN_MSEC_VALUE > d->eat_time)
		return (6);
	if (0 >= d->sleep_time || MIN_MSEC_VALUE > d->sleep_time)
		return (7);
	if (5 == ac && 0 >= d->eat_count)
		return (8);
	return (0);
}

int	validate_arg(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac < MIN_ARG_COUNT || ac > MAX_ARG_COUNT)
		return (1);
	while (++i < ac)
	{
		if (0 == ft_is_digits(av[i]))
			return (2);
		if (0 == ft_is_integer(av[i]))
			return (3);
	}
	return (0);
}
