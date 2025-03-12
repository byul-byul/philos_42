/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:26:16 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/12 12:23:07 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	sort_three(t_data *d, int stack_type)
// {
// 	int		a;
// 	int		b;
// 	int		c;
// 	t_stack	*stack;

// 	stack = tmp_a;
// 	if (stack_type == STACK_B)
// 		stack = tmp_b;
// 	a = stack->value;
// 	b = stack->next->value;
// 	c = stack->next->next->value;
// 	if (a > b && a > c)
// 	{
// 		rotate_wrapper(d, stack_type);
// 		if (stack->value > stack->next->value)
// 			swap_wrapper(d, stack_type);
// 	}
// 	else if (b > a && b > c)
// 	{
// 		rev_rotate_wrapper(d, stack_type);
// 		if (stack->value > stack->next->value)
// 			swap_wrapper(d, stack_type);
// 	}
// 	else if (a > b)
// 		swap_wrapper(d, stack_type);
// }

// static void	simplesort(t_data *d, int stack_type)
// {
// 	int		minindex;
// 	int		size;
// 	t_stack	*stack;

// 	stack = tmp_a;
// 	size = d->size_a;
// 	if (stack_type == STACK_B)
// 	{
// 		stack = tmp_b;
// 		size = d->size_b;
// 	}
// 	if (size == 3)
// 		sort_three(d, stack_type);
// 	else if (size == 2)
// 		swap_wrapper(d, stack_type);
// 	else if (size > 3)
// 	{
// 		minindex = ft_stack_minindex(stack);
// 		if (minindex < size / 2)
// 			while (minindex-- > 0)
// 				rotate_wrapper(d, stack_type);
// 		else
// 			while (minindex++ < size)
// 				rev_rotate_wrapper(d, stack_type);
// 	}
// }

// static void	do_smart_push(t_data *d, int stack_type)
// {
// 	d += 0;
// 	stack_type += 0;
// }

static void	do_push_swap(t_data *d)
{
	// if (ps->size_a > 3)
	// 	do_smart_push(ps, STACK_A);
	// simplesort(ps, STACK_A);
	// if (ps->size_b > 0)
	// {
	// 	do_smart_push(ps, STACK_B);
	// 	if (!ft_stack_is_sorted(ps->a, ASC))
	// 		simplesort(ps, STACK_A);
	// }
	d += 0;
}

void	show_stacks(t_data d);			// DELETE THIS BEFORE FINAL PUSH
void	test_operations(t_data *d);		// DELETE THIS BEFORE FINAL PUSH

int	push_swap(int ac, char **av)
{
	t_data	d;
	int		error_code;

	error_code = init_data(&d);
	if (0 == error_code)
		error_code = validate_arg(ac, av);
	if (0 == error_code)
		error_code = parse_arg(&d, ac, av);
	if (0 != error_code)
		return (print_error(error_code), clean_data(&d), error_code);
	if (0 == ft_stack_is_sorted(d.a, ASC))
		do_push_swap(&d);
	show_stacks(d);			// DELETE THIS BEFORE FINAL PUSH
	// test_operations(&d);	// DELETE THIS BEFORE FINAL PUSH
	clean_data(&d);
	return (0);
}

// DELETE EVERYTHING BELOW BEFORE FINAL PUSH --->
void	show_stacks(t_data d)
{
	int	numA;
	int	numB;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = d.a;
	tmp_b = d.b;

	ft_printf(" stack A\t stack B\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			numA = tmp_a->value;
			tmp_a = tmp_a->next;
			ft_printf("|%6d |\t", numA);
		}
		else
			ft_printf("|   -   |\t");
		if (tmp_b)
		{
			numB = tmp_b->value;
			tmp_b = tmp_b->next;
			ft_printf("|%6d |\n", numB);
		}
		else
			ft_printf("|   -   |\n");
	}
	ft_printf(" *******\t *******\n");
	if (ft_stack_is_sorted(d.a, ASC))
		ft_printf("stack is SORTED\n");
	else
		ft_printf("stack is NOT sorted\n");
	ft_printf("Count = %d\n\n", d.performed_operation_count);
}

// void	test_operations(t_data *d)
// {
// 	ft_printf("After sa:\n");
// 	swap_wrapper(d, STACK_A);
// 	show_stacks(*d);
// 	ft_printf("After pb:\n");
// 	push_wrapper(d, STACK_A);
// 	show_stacks(*d);
// 	ft_printf("After ra:\n");
// 	rotate_wrapper(d, STACK_A);
// 	show_stacks(*d);
// 	ft_printf("After rra:\n");
// 	rev_rotate_wrapper(d, STACK_A);
// 	show_stacks(*d);
// 	ft_printf("After pb:\n");
// 	push_wrapper(d, STACK_A);
// 	show_stacks(*d);
// 	ft_printf("After rrr:\n");
// 	double_rev_rotate_wrapper(d);
// 	show_stacks(*d);
// 	ft_printf("After sb:\n");
// 	swap_wrapper(d, STACK_B);
// 	show_stacks(*d);
// }