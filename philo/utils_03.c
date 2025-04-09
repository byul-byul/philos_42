/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:28:52 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/09 15:12:59 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	rise_simulation_endflag(t_data *d)
{
	pthread_mutex_lock(&d->updater);
	d->end_simulation = 1;
	pthread_mutex_unlock(&d->updater);
}

int	is_simulation_endflag_rised(t_data *d)
{
	int	is_rised;

	pthread_mutex_lock(&d->updater);
	is_rised = (1 == d->end_simulation);
	pthread_mutex_unlock(&d->updater);
	return (is_rised);
}

int	is_philo_died(t_data *d, t_time curr_time, t_time last_meal_time)
{
	int	is_died;

	pthread_mutex_lock(&d->updater);
	is_died = (curr_time - last_meal_time) > d->die_time;
	pthread_mutex_unlock(&d->updater);
	return (is_died);
}

int	is_all_philos_finished(t_data *d)
{
	int	is_finished;

	pthread_mutex_lock(&d->updater);
	is_finished = (d->finished_philo_count >= d->philo_count);
	pthread_mutex_unlock(&d->updater);
	return (is_finished);
}
