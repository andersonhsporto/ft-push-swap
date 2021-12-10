/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:09:08 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/09 15:13:07 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_swap *data, int status)
{
	int	temp;
	int	index;

	if (data->store.len_stack_a == 0)
		return ;
	temp = data->store.stack_a[0];
	index = 0;
	while (index < (data->store.len_stack_a - 1))
	{
		data->store.stack_a[index] = data->store.stack_a[index + 1];
		index++;
	}
	data->store.stack_a[data->store.len_stack_a - 1] = temp;
	if (status == 1)
		ft_putstr_fd("ra\n", 1);
	return ;
}

void	rotate_b(t_swap *data, int status)
{
	int	temp;
	int	index;

	temp = data->store.stack_b[0];
	index = 0;
	while (index < data->store.len_stack_b)
	{
		data->store.stack_b[index] = data->store.stack_b[index + 1];
		index++;
	}
	data->store.stack_b[data->store.len_stack_b] = temp;
	if (status == 1)
		ft_putstr_fd("rb\n", 1);
	return ;
}

void	rotate_r(t_swap *data)
{
	rotate_a(data, 0);
	rotate_b(data, 0);
	ft_putstr_fd("rr\n", 1);
	return ;
}
