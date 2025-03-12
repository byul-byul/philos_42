/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 01:14:27 by bhajili           #+#    #+#             */
/*   Updated: 2025/02/24 14:38:24 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push(t_stack **begin, t_stack *elem)
{
	if (begin && elem)
	{
		elem->next = *begin;
		*begin = elem;
	}
}

void	ft_stack_push_back(t_stack **begin, t_stack *elem)
{
	if (begin && elem)
	{
		elem->next = NULL;
		if (NULL == *begin)
			*begin = elem;
		else
			ft_stack_bottom(*begin)->next = elem;
	}
}

t_stack	*ft_stack_pop(t_stack **begin)
{
	t_stack	*taken;

	taken = NULL;
	if (begin && *begin)
	{
		taken = *begin;
		*begin = (*begin)->next;
		taken->next = NULL;
	}
	return (taken);
}

t_stack	*ft_stack_pop_back(t_stack **begin)
{
	t_stack	*taken;
	t_stack	*tmp;

	taken = NULL;
	tmp = *begin;
	if (begin && *begin)
	{
		taken = ft_stack_bottom(*begin);
		if (taken == *begin)
			(*begin) = NULL;
		else
		{
			while (tmp->next != taken)
				tmp = tmp->next;
			tmp->next = NULL;
		}
	}
	return (taken);
}

void	ft_stack_swap(t_stack **begin)
{
	t_stack	*tmp;

	if (begin && *begin && (*begin)->next)
	{
		tmp = (*begin)->next;
		(*begin)->next = (*begin)->next->next;
		tmp->next = *begin;
		*begin = tmp;
	}
}
