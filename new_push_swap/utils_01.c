/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:39:31 by byulbyul          #+#    #+#             */
/*   Updated: 2025/03/12 10:24:31 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	while (ft_issign(*str))
		if (*str++ == '-')
			sign *= -1;
	while (*str && ft_isdigit(*str))
		num = num * 10 + *str++ - 48;
	return ((num * sign));
}

int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	return (-a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
