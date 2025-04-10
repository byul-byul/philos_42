/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:40 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/05 14:46:58 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex_list(t_data *d, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		pthread_mutex_destroy(&d->fork_list[i].mutex);
}

void	clean_data(t_data *d)
{
	if (d->has_active_mutex)
		destroy_mutex_list(d, d->philo_count);
	if (d->has_allocated_memory)
	{
		free(d->philo_list);
		free(d->fork_list);
	}
}
