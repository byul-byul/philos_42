/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:00:58 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/11 18:15:27 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_program_semaphores(t_data *d)
{
	d->fork_list = sem_open(SEM_NAME_00, O_CREAT, S_IWUSR, d->philo_count);
	if (SEM_FAILED == d->fork_list)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_00);
	d->updater = sem_open(SEM_NAME_01, O_CREAT, S_IWUSR, 1);
	if (SEM_FAILED == d->updater)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_01);
	d->notifier = sem_open(SEM_NAME_02, O_CREAT, S_IWUSR, 1);
	if (SEM_FAILED == d->notifier)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_02);
	d->end_simulation = sem_open(SEM_NAME_03, O_CREAT, S_IWUSR, 0);
	if (SEM_FAILED == d->end_simulation)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_03);
	d->finished_philo = sem_open(SEM_NAME_04, O_CREAT, S_IWUSR, d->philo_count);
	if (SEM_FAILED == d->finished_philo)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_04);
	d->death_message = sem_open(SEM_NAME_05, O_CREAT, S_IWUSR, 0);
	if (SEM_FAILED == d->finished_philo)
		return (ERR_SEMOPEN_FAILED);
	sem_unlink(SEM_NAME_05);
	return (0);
}

static void	init_philo(t_data *d, int i)
{
	d->philo_list[i].id = i + 1;
	d->philo_list[i].data = d;
	d->philo_list[i].meal_count = 0;
}

void	pre_init_data(t_data *d)
{
	d->has_allocated_memory = 0;
	d->fork_list = SEM_FAILED;
	d->updater = SEM_FAILED;
	d->notifier = SEM_FAILED;
	d->end_simulation = SEM_FAILED;
	d->finished_philo = SEM_FAILED;
}

int	init_data(t_data *d)
{
	int	error_code;
	int	i;

	i = -1;
	error_code = init_program_semaphores(d);
	if (0 != error_code)
		return (error_code);
	d->philo_list = malloc(sizeof(t_philo) * d->philo_count);
	if (NULL == d->philo_list)
		return (ERR_MALLOC_FAILED);
	d->has_allocated_memory = 1;
	while (++i < d->philo_count)
		init_philo(d, i);
	return (0);
}
