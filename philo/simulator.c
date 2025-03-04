/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 15:21:32 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_simulation(void *arg)
{
	int	id;

	id = *(int *)arg;
	printf("I am philo № %d\n", id);
	return (NULL);
}

int	do_simulation(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->philo_count)
	{
		pthread_create(&d->philo_list[i].thread, NULL, \
		philo_simulation, &d->philo_list[i].name);
		usleep(360000);
	}
	i = -1;
	while (++i < d->philo_count)
	{
		pthread_join(d->philo_list[i].thread, NULL);
	}
	return (0);
}
