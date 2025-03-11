/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:40 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/11 09:49:25 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	close_semaphores(t_data *d)
{
	if (d->has_semaphores)
	{
		sem_close(d->fork_list);
		sem_close(d->updater);
		sem_close(d->notifier);
		sem_unlink(SEM_NAME_00);
		sem_unlink(SEM_NAME_01);
		sem_unlink(SEM_NAME_02);
	}
}

void	clean_data(t_data *d)
{
	if (d->has_allocated_memory)
		free(d->philo_list);
	close_semaphores(d);
}
