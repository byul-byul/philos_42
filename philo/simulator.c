/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/05 14:56:02 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->left->mutex);
	printf("philo № %d has taken Fork № %d as Left\n", philo->id, philo->left->id);
	pthread_mutex_lock(&philo->right->mutex);
	printf("philo № %d has taken Fork № %d as Right\n", philo->id, philo->right->id);
	// if (philo->id == 4)
	// 	usleep(7000000);
	printf("HELLO! I am philo № %d\n", philo->id);
	pthread_mutex_unlock(&philo->left->mutex);
	printf("philo № %d has dropped Fork № %d as Left\n", philo->id, philo->left->id);
	pthread_mutex_unlock(&philo->right->mutex);
	printf("philo № %d has dropped Fork № %d as Right\n", philo->id, philo->right->id);
	return (NULL);
}

int	do_simulation(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->philo_count)
	{
		pthread_create(&d->philo_list[i].thread, NULL, \
		philo_simulation, &d->philo_list[i]);
	}
	i = -1;
	while (++i < d->philo_count)
		pthread_join(d->philo_list[i].thread, NULL);
	return (0);
}
