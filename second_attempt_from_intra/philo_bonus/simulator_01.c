/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/16 11:24:45 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	simulate_thinking(t_philo *philo)
{
	if (is_simulation_endflag_rised(philo->data))
		return (1);
	print_philo_action(philo, get_current_timestamp(), PHILO_ACTION_THINK);
	return (0);
}

static int	simulate_sleeping(t_philo *philo)
{
	if (is_simulation_endflag_rised(philo->data))
		return (1);
	print_philo_action(philo, get_current_timestamp(), PHILO_ACTION_SLEEP);
	custom_usleep(philo->data, philo->data->sleep_time);
	return (0);
}

static int	start_eating(t_philo *philo)
{
	if (is_simulation_endflag_rised(philo->data))
		return (drop_forks(philo), 1);
	sem_wait(philo->updater);
	philo->last_meal_time = get_current_timestamp();
	sem_post(philo->updater);
	print_philo_action(philo, get_current_timestamp(), PHILO_ACTION_EAT);
	custom_usleep(philo->data, philo->data->eat_time);
	sem_wait(philo->updater);
	philo->meal_count += 1;
	if (philo->meal_count == philo->data->eat_count)
		sem_wait(philo->data->finished_philo);
	sem_post(philo->updater);
	return (0);
}

static int	simulate_eating(t_philo *philo)
{
	if (is_simulation_endflag_rised(philo->data))
		return (1);
	take_forks(philo);
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
