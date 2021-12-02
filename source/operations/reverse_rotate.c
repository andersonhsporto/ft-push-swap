/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:30:50 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/02 03:39:20 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_swap *data)
{
	int	temp;
	int	i;

	temp = data->store.stack_a[data->store.len_stack_a];
	i = 0;
	while (i < data->store.len_stack_a)
	{
		data->store.stack_a[i + 1] = data->store.stack_a[i];
		i++;
	}
	data->store.stack_a[0] = temp;
	return ;
}

void	reverse_rotate_b(t_swap *data)
{
	int	temp;
	int	i;

	temp = data->store.stack_b[data->store.len_stack_b];
	i = 0;
	while (i < data->store.len_stack_b)
	{
		data->store.stack_b[i + 1] = data->store.stack_b[i];
		i++;
	}
	data->store.stack_b[0] = temp;
	return ;
}

void	reverse_rotate_r(t_swap *data)
{
	reverse_rotate_a(data);
	reverse_rotate_b(data);
	return ;
}
