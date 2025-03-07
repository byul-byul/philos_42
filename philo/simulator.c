/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/07 22:59:31 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	drop_forks(t_philo *philo)
// {
// 	pthread_mutex_unlock(&philo->left->mutex);
// 	pthread_mutex_unlock(&philo->right->mutex);
// }

// void	take_forks(t_philo *philo)
// {
// 	if (philo->id % 2 == 1)
// 	{
// 		pthread_mutex_lock(&philo->left->mutex);
// 		print_philo_action(get_current_timestamp(), philo->id, 1);
// 		pthread_mutex_lock(&philo->right->mutex);
// 		print_philo_action(get_current_timestamp(), philo->id, 1);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&philo->right->mutex);
// 		print_philo_action(get_current_timestamp(), philo->id, 1);
// 		pthread_mutex_lock(&philo->left->mutex);
// 		print_philo_action(get_current_timestamp(), philo->id, 1);
// 	}
// }

// void	take_first_fork(t_philo *philo)
// {
// 	if (philo->id % 2 == 1)
// 	{
// 		pthread_mutex_lock(&philo->left->mutex);
// 		print_philo_action(get_current_timestamp(), philo->id, 1);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&philo->right->mutex);
// 		print_philo_action(get_current_timestamp(), philo->id, 1);
// 	}
// }

// void	take_second_fork(t_philo *philo)
// {
// 	if (philo->id % 2 == 1)
// 	{
// 		pthread_mutex_lock(&philo->right->mutex);
// 		print_philo_action(get_current_timestamp(), philo->id, 1);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&philo->left->mutex);
// 		print_philo_action(get_current_timestamp(), philo->id, 1);
// 	}
// }

// int	simulate_eating(t_data *d, t_philo *philo)
// {
// 	take_first_fork(philo);
// 	if (philo->data->end_simulation == 1)
// 		return (1);
// 	take_second_fork(philo);
// 	usleep(philo->data->eat_time0);
// 	philo->last_meal_time = get_current_timestamp();
// 	philo->meal_count++;
// 	if (philo->meal_count >= philo->data->meal_count)
// 		philo->data->finished_philo_count++;
// 	if (philo->data->finished_philo_count == philo->data->philo_count)
// 		philo->data->end_simulation = 1;
// 	drop_forks(philo);
// }

static void	finish_simulation(t_data *d, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		pthread_join(d->philo_list[i].thread, NULL);
}

int	simulate_thinking(t_philo *philo)
{
	if (philo->data->end_simulation == 1)
		return (1);
	if (print_philo_action(philo, get_current_timestamp(), 4))
		return (1);
	return (0);
}

int	simulate_sleeping(t_philo *philo)
{
	if (philo->data->end_simulation == 1)
		return (1);
	if (print_philo_action(philo, get_current_timestamp(), 3))
		return (1);
	custom_usleep(philo->data->sleep_time);
	return (0);
}

int	drop_forks(t_philo *philo)
{
	int err;

	err = pthread_mutex_unlock(&philo->left->mutex);
	err |= pthread_mutex_unlock(&philo->right->mutex);
	if (err)
		return (print_error(12), rise_simulation_end_flag(philo->data), 1);
	return (0);
}

int	start_eating(t_philo *philo)
{
	if (philo->data->end_simulation == 1)
		return (1);
	if (pthread_mutex_lock(&philo->data->updater) != 0)
		return (print_error(11), rise_simulation_end_flag(philo->data), 1);
	philo->last_meal_time = get_current_timestamp();
	if (pthread_mutex_unlock(&philo->data->updater) != 0)
		return (print_error(12), rise_simulation_end_flag(philo->data), 1);
	if (print_philo_action(philo, get_current_timestamp(), 2))
		return (1);
	while ((get_current_timestamp() - philo->last_meal_time) < philo->data->eat_time)
	{
		if (philo->data->end_simulation)
			return (drop_forks(philo), 1);
		custom_usleep(philo->data->eat_time);
	}
	return (0);
}

int	take_fork(t_philo *philo, int order)
{
	if (philo->data->end_simulation == 1)
		return (1);
	if (philo->id % 2 == 1 && order == 0)
		if (pthread_mutex_lock(&philo->left->mutex))
			return (print_error(11), rise_simulation_end_flag(philo->data), 1);
	if (philo->id % 2 == 1 && order == 1)
		if (pthread_mutex_lock(&philo->right->mutex))
			return (print_error(11), rise_simulation_end_flag(philo->data), 1);
	if (philo->id % 2 == 0 && order == 0)
		if (pthread_mutex_lock(&philo->right->mutex))
			return (print_error(11), rise_simulation_end_flag(philo->data), 1);
	if (philo->id % 2 == 0 && order == 1)
		if (pthread_mutex_lock(&philo->left->mutex))
			return (print_error(11), rise_simulation_end_flag(philo->data), 1);
	if (print_philo_action(philo, get_current_timestamp(), 1))
		return (rise_simulation_end_flag(philo->data), 1);
	return (0);
}

int	simulate_eating(t_philo *philo)
{
	if (take_fork(philo, 0))
		return (1);
	if (take_fork(philo, 1))
		return (1);
	if (start_eating(philo))
		return (1);
	if (drop_forks(philo))
		return (1);
	return (0);
}

static void	*simulate_philo(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->data->end_simulation == 1)
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

int	monitor_simulation(t_data *d)
{
	int	i;

	while (0 == d->end_simulation)
	{
		i = -1;
		while (++i < d->philo_count)
		{
			if (pthread_mutex_lock(&d->updater) != 0)
				return (print_error(11), rise_simulation_end_flag(d), 1);
			if ((get_current_timestamp() - d->philo_list[i].last_meal_time) > d->die_time)
			{
				d->end_simulation = 1;
				printf("d->end_simulation becomes 1 for i = %d\n", i);
				print_philo_action(&d->philo_list[i], get_current_timestamp(), 5);
				break ;
			}
			if (pthread_mutex_unlock(&d->updater) != 0)
				return (print_error(12), rise_simulation_end_flag(d), 1);
		}
		usleep(CUSTOM_USLEEP_TIME);
	}
	return (0);
}

int	do_simulation(t_data *d)
{
	int			i;
	long long	simulation_start_time;

	i = -1;
	simulation_start_time = get_current_timestamp();
	while (++i < d->philo_count)
	{
		d->philo_list[i].last_meal_time = simulation_start_time;
		if (pthread_create(&d->philo_list[i].thread, NULL, \
			simulate_philo, &d->philo_list[i]))
		{
			print_error(13);
			d->end_simulation = 1;
			break ;
		}
	}
	monitor_simulation(d);
	if (i < d->philo_count)
		return (finish_simulation(d, i), 1);
	return (finish_simulation(d, i), 0);
}
