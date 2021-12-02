/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:09:08 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/01 23:28:28 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_swap *data)
{
	int	temp;
	int	i;

	temp = data->store.stack_a[0];
	i = 0;
	while (i < data->store.len_stack_a)
	{
		data->store.stack_a[i] = data->store.stack_a[i + 1];
		i++;
	}
	data->store.stack_a[data->store.len_stack_a] = temp;
	return ;
}

void	rotate_b(t_swap *data)
{
	int	temp;
	int	i;

	temp = data->store.stack_b[0];
	i = 0;
	while (i < data->store.len_stack_b)
	{
		data->store.stack_b[i] = data->store.stack_b[i + 1];
		i++;
	}
	data->store.stack_b[data->store.len_stack_b] = temp;
	return ;
}

void	rotate_r(t_swap *data)
{
	rotate_a(data);
	rotate_b(data);
	return ;
}
