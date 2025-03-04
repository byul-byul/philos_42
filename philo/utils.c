/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:37:51 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/04 10:48:11 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(const char c)
{
	return (c > 47 && c < 58);
}

int	is_only_digits(const char *str)
{
	if (NULL == str)
		return (0);
	while (*str)
		if (0 == is_digit(*str++))
			return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	return (atol(str));
}

int	is_integer(const char *str)
{
	long	num;

	num	= ft_atol(str);
	return (num <= MAX_INT && num >= MIN_INT);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (NULL == str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_error(int error_code)
{
	if (ERR_MSG_ENABLED == TRUE)
	{
		if (error_code == 0)
			return ;
		else if (error_code == 1)
			ft_putstr(ERR_MSG_01);
		else if (error_code == 2)
			ft_putstr(ERR_MSG_02);
		else if (error_code == 3)
			ft_putstr(ERR_MSG_03);
		else if (error_code == 4)
			ft_putstr(ERR_MSG_04);
		else if (error_code == 5)
			ft_putstr(ERR_MSG_05);
		else
			ft_putstr(ERR_MSG_00);
	}
	else if (error_code > 0)
		ft_putstr(ERR_MSG_00);
}
