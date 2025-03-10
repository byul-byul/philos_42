/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:00:58 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/10 06:20:40 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_program_sems(t_data *d)
{
	sem_unlink(SEM_NAME_00);
	d->fork_list = sem_open(SEM_NAME_00, O_CREAT, S_IWUSR, d->philo_count);
	if (SEM_FAILED == d->fork_list)
		return (10);
	sem_unlink(SEM_NAME_01);
	d->updater = sem_open(SEM_NAME_01, O_CREAT, S_IWUSR, 1);
	if (SEM_FAILED == d->updater)
		return (sem_close(d->fork_list), sem_unlink(SEM_NAME_00), 10);
	sem_unlink(SEM_NAME_02);
	d->notifier = sem_open(SEM_NAME_02, O_CREAT, S_IWUSR, 1);
	if (SEM_FAILED == d->notifier)
		return (sem_close(d->fork_list), sem_unlink(SEM_NAME_00), \
				sem_close(d->updater), sem_unlink(SEM_NAME_01), 10);
	return (0);
}

static void	init_philo(t_data *d, int i)
{
	d->philo_list[i].id = i + 1;
	d->philo_list[i].data = d;
	d->philo_list[i].meal_count = 0;
}

static void	init_simple_data_fields(t_data *d)
{
	d->has_allocated_memory = 0;
	d->end_simulation = 0;
	d->finished_philo_count = 0;
}

int	init_data(t_data *d)
{
	int	error_code;
	int	i;

	i = -1;
	error_code = 0;
	init_simple_data_fields(d);
	error_code = init_program_sems(d);
	if (0 != error_code)
		return (error_code);
	d->philo_list = malloc(sizeof(t_philo) * d->philo_count);
	if (NULL == d->philo_list)
		return (9);
	d->has_allocated_memory = 1;
	while (++i < d->philo_count)
		init_philo(d, i);
	return (0);
}
