/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:04:23 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/23 10:04:33 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	rise_simulation_endflag(t_data *d)
{
	sem_post(d->end_simulation);
}

int	is_simulation_endflag_rised(t_data *d)
{
	int	sem_value;

	sem_getvalue(d->end_simulation, &sem_value);
	return (sem_value > 0);
}

int	is_all_philos_finished(t_data *d)
{
	int	sem_value;

	sem_getvalue(d->finished_philo, &sem_value);
	return (sem_value >= d->philo_count);
}
