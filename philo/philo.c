/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:33:44 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 15:17:08 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_data data)
{
	int	i;

	i = -1;
	printf("number_of_philosophers:\t\t\t\t%d\n", data.philo_count);
	printf("time_to_die:\t\t\t\t\t%lld\n", data.die_time);
	printf("time_to_eat:\t\t\t\t\t%lld\n", data.eat_time);
	printf("time_to_sleep:\t\t\t\t\t%lld\n", data.sleep_time);
	printf("number_of_times_each_philosopher_must_eat:\t%d\n", data.eat_count);
	while (++i < data.philo_count)
	{
		printf("philo № %d\n", data.philo_list[i].name);
	}
}

void	philo(int ac, char **av)
{
	int		error_code;
	t_data	d;

	error_code = validate_arg(ac, av);
	if (0 == error_code)
		error_code = parse_arg(ac, av, &d);
	if (0 == error_code)
		error_code = validate_data(ac, &d);
	if (0 == error_code)
		error_code = init_data(&d);
	if (0 == error_code)
		error_code = do_simulation(&d);
	print_error(error_code);
	// if (0 == error_code)
	// 	print_data(d);
}
