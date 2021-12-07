/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilogy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:08:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/07 01:57:52 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	continue_scan(t_swap *data);

void	scan_status(t_swap *data)
{
	if (data->store.stack_a[0] > data->store.stack_a[1] && \
		data->store.stack_a[2] > data->store.stack_a[1] && \
		data->store.stack_a[2] > data->store.stack_a[0])
	{
		swap_a(data);
	}
	if (data->store.stack_a[0] > data->store.stack_a[1] && \
		data->store.stack_a[1] > data->store.stack_a[2] && \
		data->store.stack_a[2] < data->store.stack_a[0])
	{
		swap_a(data);
		reverse_rotate_a(data, 1);
	}
	if (data->store.stack_a[0] > data->store.stack_a[1] && \
		data->store.stack_a[1] < data->store.stack_a[2] && \
		data->store.stack_a[2] < data->store.stack_a[0])
	{
		rotate_a(data, 1);
	}
	continue_scan(data);
}

void	continue_scan(t_swap *data)
{
	if (data->store.stack_a[0] < data->store.stack_a[1] && \
		data->store.stack_a[1] > data->store.stack_a[2] && \
		data->store.stack_a[2] < data->store.stack_a[0])
	{
		reverse_rotate_a(data, 1);
	}
	if (data->store.stack_a[0] < data->store.stack_a[1] && \
		data->store.stack_a[1] > data->store.stack_a[2] && \
		data->store.stack_a[2] > data->store.stack_a[0])
	{
		swap_a(data);
		rotate_a(data, 1);
	}
	return ;
}
