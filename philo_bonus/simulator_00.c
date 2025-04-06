/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/06 12:08:43 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	finish_simulation(t_data *d, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		waitpid(d->philo_list[i].pid, NULL, 0);
}

static void	*monitor_simulation(void *arg)
{
	t_philo		*philo;
	long long	current_time;

	philo = (t_philo *)arg;
	while (0 == is_simulation_endflag_rised(philo->data))
	{
		current_time = get_current_timestamp();
		if ((current_time - philo->last_meal_time) > philo->data->die_time)
		{
			rise_simulation_endflag(philo->data);
			print_philo_action(philo, current_time, PHILO_ACTION_DIE);
			break ;
		}
		if (is_all_philos_finished(philo->data))
		{
			rise_simulation_endflag(philo->data);
			break ;
		}
		usleep(MIN_USLEEP_TIME);
	}
	return (NULL);
}

static void	*simulate_lonely_philo(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (is_simulation_endflag_rised(philo->data))
		return (NULL);
	sem_wait(philo->data->fork_list);
	print_philo_action(philo, get_current_timestamp(), PHILO_ACTION_TAKE_FORK);
	custom_usleep(philo->data, philo->data->die_time);
	print_philo_action(philo, get_current_timestamp(), PHILO_ACTION_DIE);
	sem_post(philo->data->fork_list);
	return (NULL);
}

static int	handle_lonely_philo(t_data *d)
{
	t_philo		*philo;

	philo = &d->philo_list[0];
	philo->last_meal_time = get_current_timestamp();
	philo->pid = fork();
	if (philo->pid < 0)
		return (ERR_FORK_FAILED);
	if (philo->pid == 0)
	{
		simulate_lonely_philo(philo);
		exit(0);
	}
	finish_simulation(d, d->philo_count);
	return (0);
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
		philo->pid = fork();
		if (philo->pid < 0)
			return (rise_simulation_endflag(d), finish_simulation(d, i), \
					ERR_FORK_FAILED);
		if (philo->pid != 0)
			continue ;
		if (pthread_create(&philo->thread, NULL, monitor_simulation, philo))
			return (rise_simulation_endflag(d), finish_simulation(d, i), ERR_P);
		pthread_detach(philo->thread);
		simulate_philo(philo);
		exit(0);
	}
	return (finish_simulation(d, d->philo_count), 0);
}
