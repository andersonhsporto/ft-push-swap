/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:47:20 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/09 15:15:52 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_value(t_swap *data);

void	worst_algo(t_swap *data)
{
	int	i;

	find_value(data);
	i = 0;
	while (data->store.len_stack_a > 0)
	{
		rotate_a(data, 1);
		if (data->store.stack_a[0] == data->value.min)
		{
			push(data, pb);
			find_value(data);
		}
		i++;
	}
	while (data->store.len_stack_b > 0)
	{
		push(data, pa);
	}
}

void	find_value(t_swap *data)
{
	int	index;

	if (data->store.len_stack_a == 0)
		return ;
	data->value.max = data->store.stack_a[0];
	data->value.min = data->store.stack_a[0];
	index = 0;
	while (index < data->store.len_stack_a)
	{
		if (data->store.stack_a[index] < data->value.min)
			data->value.min = data->store.stack_a[index];
		if (data->store.stack_a[index] > data->value.max)
			data->value.max = data->store.stack_a[index];
		index++;
	}
	return ;
}
