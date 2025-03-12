/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_operations_00.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:07:57 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/12 11:15:49 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *d)
{
	ft_stack_swap(&d->a);
}

void	pa(t_data *d)
{
	ft_stack_push(&d->a, ft_stack_pop(&d->b));
}

void	ra(t_data *d)
{
	ft_stack_push_back(&d->a, ft_stack_pop(&d->a));
}

void	rra(t_data *d)
{
	ft_stack_push(&d->a, ft_stack_pop_back(&d->a));
}
