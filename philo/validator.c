/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:10:21 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 10:48:09 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_arg(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac < 5 || ac > 6)
		return (1);
	while (++i < ac)
	{
		if (0 == is_only_digits(av[i]))
			return (2);
		if (0 == is_integer(av[i]))
			return (3);
	}
	return (0);
}
