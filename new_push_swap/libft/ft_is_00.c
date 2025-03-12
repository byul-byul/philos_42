/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:08:58 by bhajili           #+#    #+#             */
/*   Updated: 2024/08/25 10:45:23 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
