/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:27:11 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/15 14:59:48 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_is_digit(const char c)
{
	return (c > 47 && c < 58);
}

int	ft_is_digits(const char *str)
{
	if (NULL == str)
		return (0);
	while (*str)
		if (0 == ft_is_digit(*str++))
			return (0);
	return (1);
}

long long	ft_atoll(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str && ft_is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str && ft_is_digit(*str))
		num = num * 10 + *str++ - 48;
	return ((num * sign));
}

int	ft_atoi(const char *str)
{
	return ((int)ft_atoll(str));
}
