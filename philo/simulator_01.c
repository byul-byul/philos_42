/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/23 09:19:28 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	simulate_thinking(t_philo *philo)
{
	if (is_simulation_endflag_rised(philo->data))
		return (1);
	print_philo_action(philo, get_current_timestamp(), 4);
	return (0);
}

static int	simulate_sleeping(t_philo *philo)
{
	if (is_simulation_endflag_rised(philo->data))
		return (1);
	print_philo_action(philo, get_current_timestamp(), 3);
	custom_usleep(philo->data, philo->data->sleep_time);
	return (0);
}

static int	start_eating(t_philo *philo)
{
	if (is_simulation_endflag_rised(philo->data))
		return (drop_forks(philo), 1);
	pthread_mutex_lock(&philo->data->updater);
	philo->last_meal_time = get_current_timestamp();
	philo->meal_count += 1;
	if (philo->data->eat_count != -1 && \
		philo->meal_count == philo->data->eat_count)
		philo->data->finished_philo_count++;
	pthread_mutex_unlock(&philo->data->updater);
	print_philo_action(philo, get_current_timestamp(), 2);
	custom_usleep(philo->data, philo->data->eat_time);
	return (0);
}

static int	simulate_eating(t_philo *philo)
{
	if (is_simulation_endflag_rised(philo->data))
		return (1);
	take_fork(philo, 0);
	if (is_simulation_endflag_rised(philo->data))
		return (drop_fork(philo, 0), 1);
	take_fork(philo, 1);
	if (is_simulation_endflag_rised(philo->data))
		return (drop_forks(philo), 1);
	if (start_eating(philo))
		return (drop_forks(philo), 1);
	return (drop_forks(philo), 0);
}

void	*simulate_philo(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (is_simulation_endflag_rised(philo->data))
		return (NULL);
	while (1)
	{
		if (simulate_eating(philo))
			break ;
		if (simulate_sleeping(philo))
			break ;
		if (simulate_thinking(philo))
			break ;
	}
	return (NULL);
}
