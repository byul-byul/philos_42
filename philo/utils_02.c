/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:28:52 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/08 13:59:28 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void	print_philo_action(t_philo *philo, long long tstamp, int msg_code)
{
	tstamp -= philo->data->simulation_start_time;
	pthread_mutex_lock(&philo->data->notifier);
	if (is_simulation_endflag_rised(philo->data) \
		&& msg_code == PHILO_ACTION_DIE)
		printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_05);
	if (0 == is_simulation_endflag_rised(philo->data))
	{
		if (msg_code == 1)
			printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_01);
		else if (msg_code == 2)
			printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_02);
		else if (msg_code == 3)
			printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_03);
		else if (msg_code == 4)
			printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_04);
		else if (msg_code == 5)
			printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_05);
		else
			printf(PHILO_MSG_00);
	}
	pthread_mutex_unlock(&philo->data->notifier);
}

void	custom_usleep(t_data *data, long long sleep_time)
{
	long long	start;

	data += 0;
	start = get_current_timestamp();
	while ((get_current_timestamp() - start) < sleep_time)
	{
		if (is_simulation_endflag_rised(data))
			break ;
		usleep(MIN_USLEEP_TIME);
	}
}

void	rise_simulation_endflag(t_data *d)
{
	pthread_mutex_lock(&d->updater);
	d->end_simulation = 1;
	pthread_mutex_unlock(&d->updater);
}

int	is_simulation_endflag_rised(t_data *d)
{
	int	is_rised;

	pthread_mutex_lock(&d->updater);
	is_rised = (1 == d->end_simulation);
	pthread_mutex_unlock(&d->updater);
	return (is_rised);
}
