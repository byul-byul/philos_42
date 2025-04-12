/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:10:21 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/06 12:07:35 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_data(int ac, t_data *d)
{
	if (0 >= d->philo_count || MAX_PHILO_COUNT < d->philo_count)
		return (ERR_DATA_PHILO_COUNT);
	if (0 >= d->die_time || MIN_MSEC_VALUE > d->die_time)
		return (ERR_DATA_DIE_TIME);
	if (0 >= d->eat_time || MIN_MSEC_VALUE > d->eat_time)
		return (ERR_DATA_EAT_TIME);
	if (0 >= d->sleep_time || MIN_MSEC_VALUE > d->sleep_time)
		return (ERR_DATA_SLEEP_TIME);
	if (5 == ac && 0 >= d->eat_count)
		return (ERR_DATA_EAT_COUNT);
	return (0);
}

int	validate_arg(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac < MIN_ARG_COUNT || ac > MAX_ARG_COUNT)
		return (ERR_ARG_COUNT);
	while (++i < ac)
	{
		if (0 == ft_is_digits(av[i]))
			return (ERR_ARG_DIGITS);
		if (0 == ft_is_integer(av[i]))
			return (ERR_ARG_INTS);
	}
	return (0);
}
