/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/15 16:44:34 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	drop_forks(t_philo *philo)
{
	drop_fork(philo);
	drop_fork(philo);
}

void	drop_fork(t_philo *philo)
{
	sem_post(philo->data->fork_list);
}

void	take_fork(t_philo *philo)
{
	sem_wait(philo->data->fork_list);
	print_philo_action(philo, get_current_timestamp(), PHILO_ACTION_TAKE_FORK);
}

// void	take_forks(t_philo *philo)
// {
// 	if (0 == philo->id % 2)
// 	{
// 		usleep(MIN_USLEEP_TIME);
// 		take_fork(philo);
// 		if (is_simulation_endflag_rised(philo->data))
// 		{
// 			drop_fork(philo);
// 			return ;
// 		}
// 		take_fork(philo);
// 	}
// 	else
// 	{
// 		take_fork(philo);
// 		if (is_simulation_endflag_rised(philo->data))
// 		{
// 			drop_fork(philo);
// 			return ;
// 		}
// 		take_fork(philo);
// 	}
// }

void take_forks(t_philo *philo)
{
    // Always try to take fork 1 first, then fork 2 (or the first and second available forks)
    if (philo->id % 2 == 0)
        usleep(MIN_USLEEP_TIME);  // Even philosophers wait before taking forks

    // Take fork 1 first, then fork 2 (or vice versa, but in a predictable order)
    sem_wait(philo->data->fork_list);  // Wait for fork 1
    print_philo_action(philo, get_current_timestamp(), PHILO_ACTION_TAKE_FORK);

    if (is_simulation_endflag_rised(philo->data)) {
        sem_post(philo->data->fork_list);  // Release fork 1 if simulation ends
        return;
    }

    sem_wait(philo->data->fork_list);  // Wait for fork 2
    print_philo_action(philo, get_current_timestamp(), PHILO_ACTION_TAKE_FORK);
}
