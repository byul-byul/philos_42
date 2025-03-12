/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_00.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 01:14:27 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/02 09:52:39 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->value = value;
		new->next = NULL;
	}
	return (new);
}

int	ft_stack_add(t_stack **begin, int value)
{
	t_stack	*elem;

	elem = ft_stack_new(value);
	if (!elem)
		return (0);
	ft_stack_push_back(begin, elem);
	return (1);
}

int	ft_stack_is_in(t_stack *begin, int value)
{
	while (begin)
	{
		if (begin->value == value)
			return (1);
		begin = begin->next;
	}
	return (0);
}

t_stack	*ft_stack_bottom(t_stack *begin)
{
	if (begin)
		while (begin->next)
			begin = begin->next;
	return (begin);
}

void	ft_stack_clean(t_stack **begin)
{
	t_stack	*tmp;

	if (NULL == begin)
		return ;
	while (*begin)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		free(tmp);
	}
	begin = NULL;
}
