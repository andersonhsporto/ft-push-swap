/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:37:35 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/01 21:00:15 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_swap *data)
{
	if (data->store.len_stack_a > 0)
	{
		add_integer(data->store.stack_a[0],
			&data->store.stack_b, data->store.len_stack_b);
		data->store.len_stack_b += 1;
		delete_integer(&data->store.stack_a,
			data->store.len_stack_a);
		data->store.len_stack_a -= 1;
	}
	return ;
}

void	push_b(t_swap *data)
{
	if (data->store.len_stack_b > 0)
	{
		add_integer(data->store.stack_b[0],
			&data->store.stack_a, data->store.len_stack_a);
		data->store.len_stack_a += 1;
		delete_integer(&data->store.stack_b,
			data->store.len_stack_b);
		data->store.len_stack_a -= 1;
	}
	return ;
}
