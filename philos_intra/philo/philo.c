/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:33:44 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/06 07:43:21 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(int ac, char **av)
{
	t_data	d;
	int		error_code;

	pre_init_data(&d);
	error_code = validate_arg(ac, av);
	if (0 == error_code)
		error_code = parse_arg(ac, av, &d);
	if (0 == error_code)
		error_code = validate_data(ac, &d);
	if (0 == error_code)
		error_code = init_data(&d);
	if (0 == error_code)
		error_code = do_simulation(&d);
	if (0 != error_code)
		print_error(error_code);
	clean_data(&d);
	return (error_code);
}
