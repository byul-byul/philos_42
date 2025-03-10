/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/10 07:09:16 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	print_philo_action(philo, get_current_timestamp(), 1);
}

void	take_forks(t_philo *philo)
{
	if (0 == philo->id % 2)
	{
		take_fork(philo);
		if (is_simulation_endflag_rised(philo->data))
		{
			drop_fork(philo);
			return ;
		}
		usleep(MIN_USLEEP_TIME);
		take_fork(philo);
	}
	else
	{
		take_fork(philo);
		if (is_simulation_endflag_rised(philo->data))
		{
			drop_fork(philo);
			return ;
		}
		take_fork(philo);
	}
}
