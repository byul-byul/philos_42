/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/12 15:40:43 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	finish_simulation(t_data *d, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		pthread_join(d->philo_list[i].thread, NULL);
}

static void	*simulate_lonely_philo(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (is_simulation_endflag_rised(philo->data))
		return (NULL);
	pthread_mutex_lock(&philo->left->mutex);
	print_philo_action(philo, get_current_timestamp(), PHILO_ACTION_TAKE_FORK);
	custom_usleep(philo->data, philo->data->die_time);
	print_philo_action(philo, get_current_timestamp(), PHILO_ACTION_DIE);
	pthread_mutex_unlock(&philo->left->mutex);
	return (NULL);
}

static int	handle_lonely_philo(t_data *d)
{
	if (pthread_create(&d->philo_list[0].thread, NULL,
			simulate_lonely_philo, &d->philo_list[0]))
	{
		print_error(ERR_PTHREAD_FAILED);
		d->end_simulation = 1;
		return (1);
	}
	pthread_join(d->philo_list[0].thread, NULL);
	return (0);
}

static void	monitor_simulation(t_data *d)
{
	int			i;
	t_philo		*philo;
	t_time		current_time;

	while (0 == is_simulation_endflag_rised(d))
	{
		i = -1;
		while (++i < d->philo_count)
		{
			philo = &d->philo_list[i];
			current_time = get_current_timestamp();
			if (is_philo_died(philo, current_time))
			{
				rise_simulation_endflag(d);
				print_philo_action(philo, current_time, PHILO_ACTION_DIE);
				break ;
			}
			if (is_all_philos_finished(d))
			{
				rise_simulation_endflag(d);
				break ;
			}
		}
		usleep(MIN_USLEEP_TIME);
	}
}

int	do_simulation(t_data *d)
{
	int			i;
	t_philo		*philo;

	d->simulation_start_time = get_current_timestamp();
	if (d->philo_count == 1)
		return (handle_lonely_philo(d));
	i = -1;
	while (++i < d->philo_count)
	{
		philo = &d->philo_list[i];
		philo->last_meal_time = d->simulation_start_time;
		if (pthread_create(&philo->thread, NULL, simulate_philo, philo))
			return (rise_simulation_endflag(d), finish_simulation(d, i),
				ERR_PTHREAD_FAILED);
	}
	monitor_simulation(d);
	finish_simulation(d, d->philo_count);
	return (0);
}
