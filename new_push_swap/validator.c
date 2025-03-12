/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:08:13 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/12 08:49:13 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_arg(int ac, char **av)
{
	char	*tmp;

	if (ac <= 0)
		return (1);
	while (*av)
	{
		tmp = *av;
		while (*tmp)
		{
			if (!ft_isspace(*tmp) && !ft_isdigit(*tmp) && !ft_issign(*tmp))
				return (2);
			tmp++;
		}
		av++;
	}
	return (0);
}
