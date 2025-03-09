/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:09:32 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/07 23:21:23 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_integer(const char *str)
{
	long	num;

	num = ft_atoll(str);
	return (num <= MAX_INT && num >= MIN_INT);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (NULL == str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_error(int error_code)
{
	if (error_code == 0 || ERR_MSG_ENABLED == FALSE)
		return ;
	if (error_code == 1)
		ft_putstr(ERR_MSG_01);
	else if (error_code == 2)
		ft_putstr(ERR_MSG_02);
	else if (error_code == 3)
		ft_putstr(ERR_MSG_03);
	else if (error_code == 4)
		ft_putstr(ERR_MSG_04);
	else if (error_code == 5)
		ft_putstr(ERR_MSG_05);
	else if (error_code == 6)
		ft_putstr(ERR_MSG_06);
	else if (error_code == 7)
		ft_putstr(ERR_MSG_07);
	else if (error_code == 8)
		ft_putstr(ERR_MSG_08);
	else if (error_code == 9)
		ft_putstr(ERR_MSG_09);
	else if (error_code == 10)
		ft_putstr(ERR_MSG_10);
	else if (error_code == 11)
		ft_putstr(ERR_MSG_11);
	else if (error_code == 12)
		ft_putstr(ERR_MSG_12);
	else
		ft_putstr(ERR_MSG_00);
}

long long	get_current_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

int	print_philo_action(t_philo *philo, long long tstamp, int msg_code)
{
	if (pthread_mutex_lock(&philo->data->notifier))
		return (print_error(11), 1);
	if (1 == philo->data->end_simulation && msg_code == 5)
		printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_05);
	if (0 == philo->data->end_simulation)
	{
		if (msg_code == 1)
			printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_01);
		else if (msg_code == 2)
			printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_02);
		else if (msg_code == 3)
			printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_03);
		else if (msg_code == 4)
			printf("%lld %d %s", tstamp, philo->id, PHILO_MSG_04);
		else
			ft_putstr(PHILO_MSG_00);
	}
	if (pthread_mutex_unlock(&philo->data->notifier))
		return (print_error(12), 1);
	return (0);
}

void	custom_usleep(long long sleep_time)
{
	long long	start;
	
	start= get_current_timestamp();
	while ((get_current_timestamp() - start) < sleep_time)
		usleep(CUSTOM_USLEEP_TIME);
}

int	rise_simulation_end_flag(t_data *d)
{
	if (pthread_mutex_lock(&d->updater) != 0)
		return (print_error(11), 1);
	d->end_simulation = 1;
	if (pthread_mutex_unlock(&d->updater))
		return (print_error(12), 1);
	return (0);
}