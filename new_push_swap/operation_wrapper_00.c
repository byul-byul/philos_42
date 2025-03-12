/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_wrapper_00.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:16:14 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/12 11:16:29 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_wrapper(t_data *d, int stack_type)
{
	if (STACK_A == stack_type)
	{
		sa(d);
		if (TRUE == OPR_MSG_ENABLED)
			ft_putstr(OPR_MSG_SA);
	}
	else
	{
		sb(d);
		if (TRUE == OPR_MSG_ENABLED)
			ft_putstr(OPR_MSG_SB);
	}
	d->performed_operation_count += 1;
}

void	push_wrapper(t_data *d, int stack_type)
{
	if (STACK_A == stack_type)
	{
		pb(d);
		d->size_a -= 1;
		d->size_b += 1;
		if (TRUE == OPR_MSG_ENABLED)
			ft_putstr(OPR_MSG_PB);
	}
	else
	{
		pa(d);
		d->size_a += 1;
		d->size_b -= 1;
		if (TRUE == OPR_MSG_ENABLED)
			ft_putstr(OPR_MSG_PA);
	}
	d->performed_operation_count += 1;
}

void	rotate_wrapper(t_data *d, int stack_type)
{
	if (STACK_A == stack_type)
	{
		ra(d);
		if (TRUE == OPR_MSG_ENABLED)
			ft_putstr(OPR_MSG_RA);
	}
	else
	{
		rb(d);
		if (TRUE == OPR_MSG_ENABLED)
			ft_putstr(OPR_MSG_RB);
	}
	d->performed_operation_count += 1;
}

void	rev_rotate_wrapper(t_data *d, int stack_type)
{
	if (STACK_A == stack_type)
	{
		rra(d);
		if (TRUE == OPR_MSG_ENABLED)
			ft_putstr(OPR_MSG_RRA);
	}
	else
	{
		rrb(d);
		if (TRUE == OPR_MSG_ENABLED)
			ft_putstr(OPR_MSG_RRB);
	}
	d->performed_operation_count += 1;
}

void	double_swap_wrapper(t_data *d)
{
	ss(d);
	if (TRUE == OPR_MSG_ENABLED)
		ft_putstr(OPR_MSG_SS);
	d->performed_operation_count += 1;
}

void	double_rotate_wrapper(t_data *d)
{
	rr(d);
	if (TRUE == OPR_MSG_ENABLED)
		ft_putstr(OPR_MSG_RR);
	d->performed_operation_count += 1;
}

void	double_rev_rotate_wrapper(t_data *d)
{
	rrr(d);
	if (TRUE == OPR_MSG_ENABLED)
		ft_putstr(OPR_MSG_RRR);
	d->performed_operation_count += 1;
}
