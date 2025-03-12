/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:10:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/12 10:19:12 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_data(t_data *d)
{
	d->a = NULL;
	d->b = NULL;
	d->size_a = 0;
	d->size_b = 0;
	d->has_allocated_memory = 0;
	d->performed_operation_count = 0;
	return (0);
}
