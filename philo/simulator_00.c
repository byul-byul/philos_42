/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/11 15:49:40 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*simulate_lonely_philo(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (is_simulation_endflag_rised(philo->data))
		return (NULL);
	pthread_mutex_lock(&philo->left->mutex);
	print_philo_action(philo, get_current_timestamp(), 1);
	custom_usleep(philo->data, philo->data->die_time);
	print_philo_action(philo, get_current_timestamp(), 5);
	pthread_mutex_unlock(&philo->left->mutex);
	return (NULL);
}

static int	handle_lonely_philo(t_data *d)
{
	if (pthread_create(&d->philo_list[0].thread, NULL, \
		simulate_lonely_philo, &d->philo_list[0]))
	{
		print_error(11);
		d->end_simulation = 1;
		return (1);
	}
	return (pthread_join(d->philo_list[0].thread, NULL), 0);
}

static void	finish_simulation(t_data *d, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		pthread_join(d->philo_list[i].thread, NULL);
}

static void	monitor_simulation(t_data *d)
{
	int			i;
	t_philo		*philo;
	long long	current_time;

	while (0 == is_simulation_endflag_rised(d))
	{
		i = -1;
		while (++i < d->philo_count)
		{
			philo = &d->philo_list[i];
			current_time = get_current_timestamp();
			if ((current_time - philo->last_meal_time) > d->die_time)
			{
				rise_simulation_endflag(d);
				print_philo_action(philo, current_time, 5);
				break ;
			}
			if (d->finished_philo_count >= d->philo_count)
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
	long long	simulation_start_time;

	if (d->philo_count == 1)
		return (handle_lonely_philo(d));
	i = -1;
	simulation_start_time = get_current_timestamp();
	while (++i < d->philo_count)
	{
		philo = &d->philo_list[i];
		philo->last_meal_time = simulation_start_time;
		if (pthread_create(&philo->thread, NULL, simulate_philo, philo))
			return (rise_simulation_endflag(d), finish_simulation(d, i), 11);
	}
	monitor_simulation(d);
	finish_simulation(d, d->philo_count);
	return (0);
}
