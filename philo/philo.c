/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:33:44 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 19:26:49 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_data d)
{
	int	i;

	i = -1;
	printf("number_of_philosophers:\t\t\t\t%d\n", d.philo_count);
	printf("time_to_die:\t\t\t\t\t%lld\n", d.die_time);
	printf("time_to_eat:\t\t\t\t\t%lld\n", d.eat_time);
	printf("time_to_sleep:\t\t\t\t\t%lld\n", d.sleep_time);
	printf("number_of_times_each_philosopher_must_eat:\t%d\n", d.eat_count);
	while (++i < d.philo_count)
	{
		printf("philo № %d\n", d.philo_list[i].id);
	}
}

void	philo(int ac, char **av)
{
	int		error_code;
	t_data	d;

	d.need_free = 0;
	error_code = validate_arg(ac, av);
	if (0 == error_code)
		error_code = parse_arg(ac, av, &d);
	if (0 == error_code)
		error_code = validate_data(ac, &d);
	if (0 == error_code)
		error_code = init_data(&d);
	if (0 == error_code)
		error_code = do_simulation(&d);
	clean_data(&d);
	print_error(error_code);
}
