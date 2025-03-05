/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:40 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/05 13:25:03 by bhajili          ###   ########.fr       */
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

	if (d->need_free)
	{
		free(d->philo_list);
		destroy_mutex_list(d, d->philo_count);
		free(d->fork_list);
	}
}
