/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:40 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/23 10:14:54 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	close_semaphores(t_data *d)
{
	if (SEM_FAILED != d->fork_list)
		sem_close(d->fork_list);
	if (SEM_FAILED != d->updater)
		sem_close(d->updater);
	if (SEM_FAILED != d->notifier)
		sem_close(d->notifier);
	if (SEM_FAILED != d->end_simulation)
		sem_close(d->end_simulation);
	if (SEM_FAILED != d->finished_philo)
		sem_close(d->finished_philo);
	sem_unlink(SEM_NAME_00);
	sem_unlink(SEM_NAME_01);
	sem_unlink(SEM_NAME_02);
	sem_unlink(SEM_NAME_03);
	sem_unlink(SEM_NAME_04);
}

void	clean_data(t_data *d)
{
	if (d->has_allocated_memory)
		free(d->philo_list);
	close_semaphores(d);
}
