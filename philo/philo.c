/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:33:44 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 12:14:37 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_data data)
{
	printf("number_of_philosophers:\t\t\t\t%d\n", data.philo_count);
	printf("time_to_die:\t\t\t\t\t%lld\n", data.die_time);
	printf("time_to_eat:\t\t\t\t\t%lld\n", data.eat_time);
	printf("time_to_sleep:\t\t\t\t\t%lld\n", data.sleep_time);
	printf("number_of_times_each_philosopher_must_eat:\t%d\n", data.eat_count);
}

int	do_simulation(int ac, char **av)
{
	ac += 0;
	av += 0;
	return (0);
}

void	philo(int ac, char **av)
{
	int		error;
	t_data	d;

	error = validate_arg(ac, av);
	if (0 == error)
		error = parse_arg(ac, av, &d);
	if (0 == error)
		error = do_simulation(ac, av);
	print_error(error);
	if (0 == error)
		print_data(d);
}
