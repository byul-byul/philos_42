/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:11:51 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 12:03:56 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_arg(int ac, char **av, t_data *data)
{
	data->philo_count = ft_atoi(av[0]);
	data->die_time = ft_atoll(av[1]);
	data->eat_time = ft_atoll(av[2]);
	data->sleep_time = ft_atoll(av[3]);
	if (ac == 5)
		data->eat_count = ft_atoi(av[4]);
	return (0);
}
