/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:00:58 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 15:13:46 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, int order)
{
	data->philo_list[order - 1].name = order;
}

int	init_data(t_data *data)
{
	int	i;

	i = -1;
	data->philo_list = malloc(sizeof(t_philo) * data->philo_count + 1);
	if (data->philo_list)
	{
		while (++i < data->philo_count)
		{
			init_philo(data, i + 1);
		}
		return (0);
	}
	return (9);
}