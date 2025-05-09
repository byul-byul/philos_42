/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:11:51 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/15 14:59:28 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	parse_arg(int ac, char **av, t_data *d)
{
	d->philo_count = ft_atoi(av[0]);
	d->die_time = ft_atoll(av[1]);
	d->eat_time = ft_atoll(av[2]);
	d->sleep_time = ft_atoll(av[3]);
	if (ac == 5)
		d->eat_count = ft_atoi(av[4]);
	else
		d->eat_count = -1;
	return (0);
}
