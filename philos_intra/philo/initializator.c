/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:00:58 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/06 11:26:57 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_data *d, int i, t_fork *left, t_fork *right)
{
	d->philo_list[i].id = i + 1;
	d->philo_list[i].left = left;
	d->philo_list[i].right = right;
	d->philo_list[i].data = d;
	d->philo_list[i].meal_count = 0;
}

static void	init_philo_list(t_data *d)
{
	int	i;
	int	n;

	i = 0;
	n = d->philo_count;
	if (n == 1)
	{
		init_philo(d, i, &d->fork_list[i], &d->fork_list[i]);
		return ;
	}
	init_philo(d, i, &d->fork_list[n - 1], &d->fork_list[i]);
	init_philo(d, n - 1, &d->fork_list[n - 2], &d->fork_list[n - 1]);
	while (++i < n - 1)
		init_philo(d, i, &d->fork_list[i - 1], &d->fork_list[i]);
}

static int	init_program_mutexes(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->philo_count)
	{
		d->fork_list[i].id = i + 1;
		if (pthread_mutex_init(&d->fork_list[i].mutex, NULL))
			return (destroy_mutex_list(d, i), ERR_MUTEXINIT_FAILED);
	}
	if (pthread_mutex_init(&d->notifier, NULL))
		return (destroy_mutex_list(d, i), ERR_MUTEXINIT_FAILED);
	if (pthread_mutex_init(&d->updater, NULL))
		return (destroy_mutex_list(d, i), \
				pthread_mutex_destroy(&d->notifier), ERR_MUTEXINIT_FAILED);
	return (0);
}

void	pre_init_data(t_data *d)
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
	d->philo_list = malloc(sizeof(t_philo) * d->philo_count);
	d->fork_list = malloc(sizeof(t_fork) * d->philo_count);
	if (NULL == d->fork_list && d->philo_list)
		free(d->philo_list);
	else if (NULL == d->philo_list && d->fork_list)
		free(d->fork_list);
	else if (d->philo_list && d->fork_list)
	{
		d->has_allocated_memory = 1;
		error_code = init_program_mutexes(d);
		if (0 != error_code)
			return (error_code);
		d->has_active_mutex = 1;
		init_philo_list(d);
		return (0);
	}
	return (ERR_MALLOC_FAILED);
}
