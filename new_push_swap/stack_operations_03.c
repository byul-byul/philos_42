/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_03.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 04:52:58 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/12 10:16:58 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_is_sorted(t_stack *begin, int sort_type)
{
	if (sort_type == ASC)
	{
		while (begin && begin->next)
		{
			if (begin->value > begin->next->value)
				return (0);
			begin = begin->next;
		}
	}
	else
	{
		while (begin && begin->next)
		{
			if (begin->value < begin->next->value)
				return (0);
			begin = begin->next;
		}
	}
	return (1);
}

int ft_stack_index(t_stack *begin, t_stack *elem)
{
	int	i;

	i = 0;
	while (begin)
	{
		if (begin == elem)
			return (i);
		begin = begin->next;
		i++;
	}
	return (-1);
}
