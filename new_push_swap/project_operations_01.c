/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_operations_01.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:07:57 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/12 11:04:32 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_data *d)
{
	ft_stack_swap(&d->b);
}

void	pb(t_data *d)
{
	ft_stack_push(&d->b, ft_stack_pop(&d->a));
}

void	rb(t_data *d)
{
	ft_stack_push_back(&d->b, ft_stack_pop(&d->b));
}

void	rrb(t_data *d)
{
	ft_stack_push(&d->b, ft_stack_pop_back(&d->b));
}
