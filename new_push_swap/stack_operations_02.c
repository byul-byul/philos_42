/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 01:14:27 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/12 09:08:37 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_stack_size(t_stack *begin)
{
	size_t	size;

	size = 0;
	while (begin)
	{
		size++;
		begin = begin->next;
	}
	return (size);
}

int	ft_stack_minvalue(t_stack *begin)
{
	int	min;

	min = begin->value;
	while (begin)
	{
		if (begin->value < min)
			min = begin->value;
		begin = begin->next;
	}
	return (min);
}

int	ft_stack_maxvalue(t_stack *begin)
{
	int	max;

	max = begin->value;
	while (begin)
	{
		if (begin->value > max)
			max = begin->value;
		begin = begin->next;
	}
	return (max);
}

int	ft_stack_minindex(t_stack *begin)
{
	int	i;
	int	min;

	i = 0;
	min = ft_stack_minvalue(begin);
	while (begin)
	{
		if (min == begin->value)
			return (i);
		begin = begin->next;
		i++;
	}
	return (-1);
}

int	ft_stack_maxindex(t_stack *begin)
{
	int	i;
	int	max;

	i = 0;
	max = ft_stack_maxvalue(begin);
	while (begin)
	{
		if (max == begin->value)
			return (i);
		begin = begin->next;
		i++;
	}
	return (-1);
}
