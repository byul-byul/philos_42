/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:04:23 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/06 10:01:37 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	rise_simulation_endflag(t_data *d)
{
	sem_wait(d->updater);
	sem_post(d->end_simulation);
	sem_post(d->updater);
}

int	is_simulation_endflag_rised(t_data *d)
{
	int	sem_value;
	int	result;

	sem_wait(d->updater);
	sem_value = sem_trywait(d->end_simulation);
	if (sem_value == -1)
		result = 0;
	else
	{
		result = 1;
		sem_post(d->end_simulation);
	}
	sem_post(d->updater);
	return (result);
}

int	is_all_philos_finished(t_data *d)
{
	int	sem_value;
	int	result;

	sem_wait(d->updater);
	sem_value = sem_trywait(d->finished_philo);
	if (sem_value == -1)
		result = 1;
	else
	{
		result = 0;
		sem_post(d->finished_philo);
	}
	sem_post(d->updater);
	return (result);
}
