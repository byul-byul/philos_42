/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:00:58 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/05 06:52:50 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo_list(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->philo_count)
	{
		d->philo_list[i].id = i + 1;
		d->philo_list[i].left = &d->fork_list[0].mutex;
		d->philo_list[i].right= &d->fork_list[1].mutex;
	}
}

void	init_mutex_list(t_data *d)
{
	int	i;

	i = -1;
	while (++i < 2)
		pthread_mutex_init(&d->fork_list[i].mutex, NULL);
}

int	init_data(t_data *d)
{
	d->need_free = 0;
	d->philo_list = malloc(sizeof(t_philo) * d->philo_count);
	d->fork_list = malloc(sizeof(t_fork) * 2);
	if (d->philo_list && !d->fork_list)
		free(d->philo_list);
	else if (!d->philo_list && d->fork_list)
		free(d->fork_list);
	else if (d->philo_list && d->fork_list)
	{
		d->need_free = 1;
		init_mutex_list(d);
		init_philo_list(d);
		return (0);
	}
	return (9);
}
