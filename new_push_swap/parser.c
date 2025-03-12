/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:47:10 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/12 10:42:58 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_to_stack(t_stack **stack, long number)
{
	if (number > MAX_INT || number < MIN_INT)
		return (4);
	if (ft_stack_is_in(*stack, number))
		return (5);
	if (ft_stack_add(stack, number) == 0)
		return (6);
	return (0);
}

int	parse_arg(t_data *d, int ac, char **av)
{
	char	**numbers;
	char	**tmp;
	int		error_code;

	numbers = av;
	if (ac == 1)
		numbers = ft_split(av[0], ' ');
	if (!numbers)
		return (3);
	tmp = numbers;
	while (*numbers)
	{
		error_code = parse_to_stack(&d->a, ft_atol(*numbers++));
		if (0 != error_code && ac == 1)
			return (ft_freearr(tmp, ft_arrsize(tmp)), error_code);
		if (0 != error_code)
			return (error_code);
		d->size_a += 1;
		d->has_allocated_memory = 1;
	}
	if (ac == 1)
		ft_freearr(tmp, ft_arrsize(tmp));
	return (0);
}
