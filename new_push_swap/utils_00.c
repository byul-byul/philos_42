/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:39:31 by byulbyul          #+#    #+#             */
/*   Updated: 2025/03/12 10:12:02 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_arrsize(char **arr)
{
	size_t	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

void	print_error(int error_code)
{
	if (0 == error_code)
		return ;
	if (ERR_MSG_ENABLED == TRUE)
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
		else
			ft_putstr(ERR_MSG_00);
	}
	else
		ft_putstr(ERR_MSG_00);
}
