/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:09:32 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/09 13:28:50 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_integer(const char *str)
{
	long	num;

	num = ft_atoll(str);
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

static void	print_error_01_11(int error_code)
{
	if (error_code == 1)
		ft_putstr(ERR_MSG_01);
	else if (error_code == 2)
		ft_putstr(ERR_MSG_02);
	else if (error_code == 3)
		ft_putstr(ERR_MSG_03);
	else if (error_code == 4)
		ft_putstr(ERR_MSG_04);
	else if (error_code == 5)
		ft_putstr(ERR_MSG_05);
	else if (error_code == 6)
		ft_putstr(ERR_MSG_06);
	else if (error_code == 7)
		ft_putstr(ERR_MSG_07);
	else if (error_code == 8)
		ft_putstr(ERR_MSG_08);
	else if (error_code == 9)
		ft_putstr(ERR_MSG_09);
	else if (error_code == 10)
		ft_putstr(ERR_MSG_10);
	else if (error_code == 11)
		ft_putstr(ERR_MSG_11);
}

void	print_error(int error_code)
{
	if (error_code == 0 || ERR_MSG_ENABLED == FALSE)
		return ;
	if (error_code >= 1 && error_code <= 11)
		print_error_01_11(error_code);
	else
		ft_putstr(ERR_MSG_00);
}
