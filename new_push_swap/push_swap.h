/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:57:47 by byulbyul          #+#    #+#             */
/*   Updated: 2025/03/12 11:29:13 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define TRUE				1
# define FALSE				0
# define ERR_MSG_ENABLED	TRUE
# define OPR_MSG_ENABLED	TRUE

# define ASC				1
# define DESC				2
# define STACK_A			ASC
# define STACK_B			DESC

# define ERR_MSG_00	"Error\n"
# define ERR_MSG_01	"ERROR: input validation: provide input.\n"
# define ERR_MSG_02	"ERROR: input validation: provide only digits.\n"
# define ERR_MSG_03	"ERROR: input parsing: ft_split() failed.\n"
# define ERR_MSG_04	"ERROR: input parsing: provide only INTs.\n"
# define ERR_MSG_05	"ERROR: input parsing: avoid duplicates.\n"
# define ERR_MSG_06	"ERROR: input parsing: malloc() failed.\n"

# define OPR_MSG_SA		"sa\n"
# define OPR_MSG_PA		"pa\n"
# define OPR_MSG_RA		"ra\n"
# define OPR_MSG_RRA	"rra\n"
# define OPR_MSG_SB		"sb\n"
# define OPR_MSG_PB		"pb\n"
# define OPR_MSG_RB		"rb\n"
# define OPR_MSG_RRB	"rrb\n"
# define OPR_MSG_SS		"ss\n"
# define OPR_MSG_RR		"rr\n"
# define OPR_MSG_RRR	"rrr\n"

typedef struct s_push_candidate
{
	int	from_index;
	int	to_index;
	int	value;
}				t_push_candidate;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct s_data
{
	int					performed_operation_count;
	int					has_allocated_memory;
	int					size_a;
	int					size_b;
	t_stack				*a;
	t_stack				*b;
	t_push_candidate	c;
}				t_data;

int		push_swap(int ac, char **av);
int		init_data(t_data *d);
int		validate_arg(int ac, char **av);
int		parse_arg(t_data *d, int ac, char **av);
void	clean_data(t_data *d);

void	print_error(int error_code);
long	ft_atol(const char *str);
int		ft_issign(char c);

size_t	ft_arrsize(char **arr);

int		ft_stack_add(t_stack **begin, int value);
t_stack	*ft_stack_new(int value);
int		ft_stack_is_in(t_stack *begin, int value);
t_stack	*ft_stack_bottom(t_stack *begin);
void	ft_stack_clean(t_stack **begin);
void	ft_stack_push(t_stack **begin, t_stack *elem);
void	ft_stack_push_back(t_stack **begin, t_stack *elem);
t_stack	*ft_stack_pop(t_stack **begin);
t_stack	*ft_stack_pop_back(t_stack **begin);
void	ft_stack_swap(t_stack **begin);

int		ft_stack_is_sorted(t_stack *begin, int sort_type);
int 	ft_stack_index(t_stack *begin, t_stack *elem);

// void	clean_ps(t_ps *ps);
// void	print_error(int error_code);

// t_stack	*ft_stack_new(int value);
// int		ft_stack_add(t_stack **begin, int value);
// int		ft_stack_is_in(t_stack *begin, int value);
// t_stack	*ft_stack_bottom(t_stack *begin);
// void	ft_stack_clean(t_stack **begin);
// void	ft_stack_push(t_stack **begin, t_stack *elem);
// void	ft_stack_push_back(t_stack **begin, t_stack *elem);
// t_stack	*ft_stack_pop(t_stack **begin);
// t_stack	*ft_stack_pop_back(t_stack **begin);
// void	ft_stack_swap(t_stack **begin);
// // size_t	ft_stack_size(t_stack *begin);
// int		ft_stack_size(t_stack *begin);
// int		ft_stack_minvalue(t_stack *begin);
// int		ft_stack_maxvalue(t_stack *begin);
// int		ft_stack_minindex(t_stack *begin);
// int		ft_stack_maxindex(t_stack *begin);

// int		ft_stack_is_sorted(t_stack *begin, int sort_type);
// int 	ft_stack_index(t_stack *begin, t_stack *elem);

// REIMPLEMENT OR CHECK NEXT FUNCS
// int		ft_issign(char c);
// long	ft_atol(const char *str);
// int		ft_abs(int a);
// int		ft_max(int a, int b);
// int		ft_min(int a, int b);
// size_t	ft_arrsize(char **arr);

void	sa(t_data *d);
void	sb(t_data *d);
void	ss(t_data *d);
void	pa(t_data *d);
void	pb(t_data *d);
void	ra(t_data *d);
void	rb(t_data *d);
void	rr(t_data *d);
void	rra(t_data *d);
void	rrb(t_data *d);
void	rrr(t_data *d);

void	swap_wrapper(t_data *d, int stack_type);
void	push_wrapper(t_data *d, int stack_type);
void	rotate_wrapper(t_data *d, int stack_type);
void	rev_rotate_wrapper(t_data *d, int stack_type);
void	double_swap_wrapper(t_data *d);
void	double_rotate_wrapper(t_data *d);
void	double_rev_rotate_wrapper(t_data *d);

// void	swap_wrapper(t_stack **stack, int stack_type);
// void	push_wrapper(t_stack **from, t_stack **to, int stack_type);
// void	rotate_wrapper(t_stack **stack, int stack_type);
// void	rev_rotate_wrapper(t_stack **stack, int stack_type);
// void	double_swap_wrapper(t_stack **stack_1, t_stack **stack_2);
// void	double_rotate_wrapper(t_stack **stack_1, t_stack **stack_2);
// void	double_rev_rotate_wrapper(t_stack **stack_1, t_stack **stack_2);

// void	do_smart_push(t_ps *ps, int stack_type);
// void 	do_smart_push_to_a(t_ps *ps);
// void	find_best_candidate(t_ps *ps, int stack_type);

// void	show_stacks(t_stack *a, t_stack *b);

#endif