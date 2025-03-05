/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:00:58 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/05 13:45:43 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	init_philo_list(t_data *d)
// {
// 	int	i;
// 	int	n;

// 	i = 0;
// 	n = d->philo_count;
// 	d->philo_list[i].id = i + 1;
// 	d->philo_list[i].right = &d->fork_list[i].mutex;
// 	d->philo_list[i].left = &d->fork_list[n - 1].mutex;
// 	d->philo_list[n - 1].id = n;
// 	d->philo_list[n - 1].right = &d->fork_list[n - 1].mutex;
// 	d->philo_list[n - 1].left = &d->fork_list[n - 1].mutex;
// 	while (++i < d->philo_count - 1)
// 	{
// 		d->philo_list[i].id = i + 1;
// 		d->philo_list[i].left = &d->fork_list[i].mutex;
// 		d->philo_list[i].right= &d->fork_list[i + 1].mutex;
// 	}
// }
// void	init_edge_philos(t_data *d, int n)
// {
// 	int	i;

// 	i = 0;
// 	d->philo_list[i].id = i + 1;
// 	d->philo_list[n - 1].id = n;
// 	d->philo_list[i].right = &d->fork_list[i];
// 	d->philo_list[i].left = &d->fork_list[n - 1].mutex;
// 	d->philo_list[i].right->mutex = d->fork_list[i].mutex;
// 	d->philo_list[i].left->mutex = d->fork_list[n - 1].mutex;
// 	d->philo_list[n - 1].right->mutex = d->fork_list[n - 1].mutex;
// 	if (n > 1)
// 		d->philo_list[n - 1].left->mutex = d->fork_list[n - 2].mutex;
// 	else
// 		d->philo_list[n - 1].right->mutex = d->fork_list[n - 1].mutex;
// }

// void	init_philo_list(t_data *d)
// {
// 	int	i;
// 	int	n;

// 	i = 0;
// 	n = d->philo_count;
// 	init_edge_philos(d, n);
// 	while (++i < n - 1)
// 	{
// 		d->philo_list[i].id = i + 1;
// 		d->philo_list[i].right->mutex = d->fork_list[i].mutex;
// 		d->philo_list[i].left->mutex = d->fork_list[i - 1].mutex;
// 	}
// }

void	init_philo(t_philo *philo, int order, t_fork *left, t_fork *right)
{
	philo->id = order;
	philo->left = left;
	philo->right = right;
	philo->left->mutex = left->mutex;
	philo->right->mutex = right->mutex;
}

void	init_philo_list(t_data *d)
{
	int	i;
	int	n;

	i = 0;
	n = d->philo_count;
	init_philo(&d->philo_list[i], i + 1, &d->fork_list[n - 1], &d->fork_list[i]);
	if (n > 1)
		init_philo(&d->philo_list[n - 1], n, &d->fork_list[n - 2], &d->fork_list[n - 1]);
	else
		init_philo(&d->philo_list[n - 1], n, &d->fork_list[n - 1], &d->fork_list[n - 1]);
	while (++i < n - 1)
	{
		init_philo(&d->philo_list[i], i + 1, &d->fork_list[i - 1], &d->fork_list[i]);
	}
}

int	init_fork_list(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->philo_count)
	{
		d->fork_list[i].id = i + 1;
		if (pthread_mutex_init(&d->fork_list[i].mutex, NULL))
			return (destroy_mutex_list(d, i), 10);
	}
	return (0);
}

int	init_data(t_data *d)
{
	int	error_code;

	error_code = 0;
	d->need_free = 0;
	d->philo_list = malloc(sizeof(t_philo) * d->philo_count);
	d->fork_list = malloc(sizeof(t_fork) * d->philo_count);
	if (d->philo_list && !d->fork_list)
		free(d->philo_list);
	else if (!d->philo_list && d->fork_list)
		free(d->fork_list);
	else if (d->philo_list && d->fork_list)
	{
		d->need_free = 1;
		error_code = init_fork_list(d);
		if (error_code)	
			return (error_code);
		init_philo_list(d);
		return (0);
	}
	return (9);
}
