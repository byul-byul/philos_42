/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:26:16 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/12 10:28:42 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	sort_three(t_ps *ps, int stack_type)
// {
// 	int		a;
// 	int		b;
// 	int		c;
// 	t_stack	*stack;

// 	stack = ps->a;
// 	if (stack_type == STACK_B)
// 		stack = ps->b;
// 	a = stack->value;
// 	b = stack->next->value;
// 	c = stack->next->next->value;
// 	if (a > b && a > c)
// 	{
// 		rotate_wrapper(ps, stack_type);
// 		if (stack->value > stack->next->value)
// 			swap_wrapper(ps, stack_type);
// 	}
// 	else if (b > a && b > c)
// 	{
// 		rev_rotate_wrapper(ps, stack_type);
// 		if (stack->value > stack->next->value)
// 			swap_wrapper(ps, stack_type);
// 	}
// 	else if (a > b)
// 		swap_wrapper(ps, stack_type);
// }

// static void	simplesort(t_ps *ps, int stack_type)
// {
// 	int		minindex;
// 	int		size;
// 	t_stack	*stack;

// 	stack = ps->a;
// 	size = ps->size_a;
// 	if (stack_type == STACK_B)
// 	{
// 		stack = ps->b;
// 		size = ps->size_b;
// 	}
// 	if (size == 3)
// 		sort_three(ps, stack_type);
// 	else if (size == 2)
// 		swap_wrapper(ps, stack_type);
// 	else if (size > 3)
// 	{
// 		minindex = ft_stack_minindex(stack);
// 		if (minindex < size / 2)
// 			while (minindex-- > 0)
// 				rotate_wrapper(ps, stack_type);
// 		else
// 			while (minindex++ < size)
// 				rev_rotate_wrapper(ps, stack_type);
// 	}
// }

static int	do_push_swap(t_data *d)
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
	return (0);
}

void	show_stacks(t_stack *a, t_stack *b);

int	push_swap(int ac, char **av)
{
	t_data	d;
	int		error_code;

	error_code = init_data(&d);
	if (0 == error_code)
		error_code = validate_arg(ac, av);
	if (0 == error_code)
		error_code = parse_arg(&d, ac, av);
	if (0 == error_code && 0 == ft_stack_is_sorted(d.a, ASC))
		error_code = do_push_swap(&d);
	if (0 != error_code)
		print_error(error_code);
	show_stacks(d.a, d.b);
	clean_data(&d);
	// DELETE THIS -> BEFORE FINAL PUSH
	// if (ft_stack_is_sorted(d.a, ASC))
	// 	ft_printf("FINE\n");
	// else
	// 	ft_printf("ERROR\n");
	// ft_printf("Count = %d\n", d.performed_operation_count);
	// DELETE THIS <- BEFORE BEFORE FINAL PUSH
	return (error_code);
}

void	show_stacks(t_stack *a, t_stack *b)
{
	int	numA;
	int	numB;

	ft_printf(" stack A\t stack B\n");
	while (a || b)
	{
		if (a)
		{
			numA = a->value;
			a = a->next;
			ft_printf("|%6d |\t", numA);
		}
		else
			ft_printf("|   -   |\t");
		if (b)
		{
			numB = b->value;
			b = b->next;
			ft_printf("|%6d |\n", numB);
		}
		else
			ft_printf("|   -   |\n");
	}
	ft_printf(" *******\t *******\n\n");
}
