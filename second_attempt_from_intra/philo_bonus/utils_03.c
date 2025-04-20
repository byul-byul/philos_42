/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:04:23 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/16 11:26:29 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	rise_simulation_endflag(t_data *d)
// {
// 	int	sem_value;

// 	sem_wait(d->global_updater);
// 	sem_value = sem_trywait(d->end_simulation);
// 	if (sem_value == -1)
// 	{
// 		sem_post(d->end_simulation);
// 		sem_post(d->global_updater);
// 		return ;
// 	}
// 	else
// 	{
// 		sem_post(d->end_simulation);
// 	}
// 	sem_post(d->global_updater);
// }


// int	is_simulation_endflag_rised(t_data *d)
// {
// 	int	sem_value;
// 	int	result;

// 	sem_wait(d->global_updater);
// 	sem_value = sem_trywait(d->end_simulation);
// 	if (sem_value == -1)
// 		result = 0;
// 	else
// 	{
// 		result = 1;
// 		sem_post(d->end_simulation);
// 	}
// 	sem_post(d->global_updater);
// 	return (result);
// }

void	rise_simulation_endflag(t_data *d)
{
	sem_wait(d->global_updater);
	sem_post(d->end_simulation);
	sem_post(d->global_updater);
}

int	is_simulation_endflag_rised(t_data *d)
{
	int	result;

	sem_wait(d->global_updater);
	if (-1 == sem_trywait(d->end_simulation))
		result = 0;
	else
	{
		result = 1;
		sem_post(d->end_simulation);
	}
	sem_post(d->global_updater);
	return (result);
}

int	is_philo_died(t_data *d, t_time curr_time, t_time last_meal_time)
{
	int	is_died;

	sem_wait(d->global_updater);
	is_died = (curr_time - last_meal_time) > d->die_time;
	sem_post(d->global_updater);
	return (is_died);
}

int	is_all_philos_finished(t_data *d)
{
	int	sem_value;
	int	result;

	sem_wait(d->global_updater);
	sem_value = sem_trywait(d->finished_philo);
	if (sem_value == -1)
		result = 1;
	else
	{
		result = 0;
		sem_post(d->finished_philo);
	}
	sem_post(d->global_updater);
	return (result);
}
