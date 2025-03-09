/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/09 13:46:37 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left->mutex);
	pthread_mutex_unlock(&philo->right->mutex);
}

void	drop_fork(t_philo *philo, int order)
{
	if (philo->id % 2 == 1 && order == 0)
		pthread_mutex_unlock(&philo->left->mutex);
	if (philo->id % 2 == 1 && order == 1)
		pthread_mutex_unlock(&philo->right->mutex);
	if (philo->id % 2 == 0 && order == 0)
		pthread_mutex_unlock(&philo->right->mutex);
	if (philo->id % 2 == 0 && order == 1)
		pthread_mutex_unlock(&philo->left->mutex);
}

void	take_fork(t_philo *philo, int order)
{
	if (philo->id % 2 == 1 && order == 0)
		pthread_mutex_lock(&philo->left->mutex);
	if (philo->id % 2 == 1 && order == 1)
		pthread_mutex_lock(&philo->right->mutex);
	if (philo->id % 2 == 0 && order == 0)
		pthread_mutex_lock(&philo->right->mutex);
	if (philo->id % 2 == 0 && order == 1)
		pthread_mutex_lock(&philo->left->mutex);
	print_philo_action(philo, get_current_timestamp(), 1);
}
