/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:09:32 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/06 12:14:39 by bhajili          ###   ########.fr       */
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
	if (error_code == ERR_ARG_COUNT)
		ft_putstr(ERR_MSG_01);
	else if (error_code == ERR_ARG_DIGITS)
		ft_putstr(ERR_MSG_02);
	else if (error_code == ERR_ARG_INTS)
		ft_putstr(ERR_MSG_03);
	else if (error_code == ERR_DATA_PHILO_COUNT)
		ft_putstr(ERR_MSG_04);
	else if (error_code == ERR_DATA_DIE_TIME)
		ft_putstr(ERR_MSG_05);
	else if (error_code == ERR_DATA_EAT_TIME)
		ft_putstr(ERR_MSG_06);
	else if (error_code == ERR_DATA_SLEEP_TIME)
		ft_putstr(ERR_MSG_07);
	else if (error_code == ERR_DATA_EAT_COUNT)
		ft_putstr(ERR_MSG_08);
	else if (error_code == ERR_MALLOC_FAILED)
		ft_putstr(ERR_MSG_09);
	else if (error_code == ERR_SEMOPEN_FAILED)
		ft_putstr(ERR_MSG_10);
	else if (error_code == ERR_FORK_FAILED)
		ft_putstr(ERR_MSG_11);
}

void	print_error(int error_code)
{
	if (error_code == 0 || ERR_MSG_ENABLED == FALSE)
		return ;
	if (error_code >= 1 && error_code <= 11)
		print_error_01_11(error_code);
	else if (error_code == ERR_P)
		ft_putstr(ERR_MSG_12);
	else
		ft_putstr(ERR_MSG_00);
}
