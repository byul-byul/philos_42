/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:00:58 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/07 21:45:15 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_philo *philo, int id, t_fork *left, t_fork *right, \
						t_data *d)
{
	philo->id = id;
	philo->left = left;
	philo->right = right;
	philo->left->mutex = left->mutex;
	philo->right->mutex = right->mutex;
	philo->data = d;
	philo->meal_count = 0;
}

static void	init_philo_list(t_data *d)
{
	int	i;
	int	n;

	i = 0;
	n = d->philo_count;
	init_philo(&d->philo_list[i], i + 1, \
		&d->fork_list[n - 1], &d->fork_list[i], d);
	if (n > 1)
		init_philo(&d->philo_list[n - 1], n, \
			&d->fork_list[n - 2], &d->fork_list[n - 1], d);
	else
		init_philo(&d->philo_list[n - 1], n, \
			&d->fork_list[n - 1], &d->fork_list[n - 1], d);
	while (++i < n - 1)
		init_philo(&d->philo_list[i], i + 1, \
			&d->fork_list[i - 1], &d->fork_list[i], d);
}

static int	init_fork_list(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->philo_count)
	{
		d->fork_list[i].id = i + 1;
		if (pthread_mutex_init(&d->fork_list[i].mutex, NULL))
			return (destroy_mutex_list(d, i), 10);
	}
	if (pthread_mutex_init(&d->notifier, NULL))
		return (destroy_mutex_list(d, i), 10);
	if (pthread_mutex_init(&d->updater, NULL))
		return (destroy_mutex_list(d, i), \
				pthread_mutex_destroy(&d->notifier), 10);
	return (0);
}

static void	init_simple_data_fields(t_data *d)
{
	d->has_allocated_memory = 0;
	d->has_active_mutex = 0;
	d->end_simulation = 0;
	d->finished_philo_count = 0;
}

int	init_data(t_data *d)
{
	int	error_code;

	error_code = 0;
	init_simple_data_fields(d);
	d->philo_list = malloc(sizeof(t_philo) * d->philo_count);
	d->fork_list = malloc(sizeof(t_fork) * d->philo_count);
	if (NULL == d->fork_list && d->philo_list)
		free(d->philo_list);
	else if (NULL == d->philo_list && d->fork_list)
		free(d->fork_list);
	else if (d->philo_list && d->fork_list)
	{
		d->has_allocated_memory = 1;
		error_code = init_fork_list(d);
		if (0 != error_code)
			return (error_code);
		d->has_active_mutex = 1;
		init_philo_list(d);
		return (0);
	}
	return (9);
}
