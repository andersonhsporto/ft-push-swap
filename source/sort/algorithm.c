/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:47:20 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/09 14:45:12 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_value(t_swap *data);

void	worst_algo(t_swap *data)
{
	int i = 0;

	find_value(data);
	while (data->store.len_stack_a > 1)
	{
		rotate_a(data, 0);
		if (data->store.stack_a[0] == data->value.min)
		{
			push(data, pb);
			//printf("min = %d\n", data->value.min);
			find_value(data);
			//printf("min = %d\n", data->value.min);
		}
		i++;
	}
}

void	find_value(t_swap *data)
{
	int	i;

	data->value.max = data->store.stack_a[0];
	data->value.min = data->store.stack_a[0];
	i = 0;
	while (i < data->store.len_stack_a)
	{
		if (data->store.stack_a[i] < data->value.min)
			data->value.min = data->store.stack_a[i];
		if (data->store.stack_a[i] > data->value.max)
			data->value.max = data->store.stack_a[i];
		i++;
	}
	return ;
}
