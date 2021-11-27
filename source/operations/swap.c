/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:48:07 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/25 00:40:09 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_swap *data)
{
	int	*temp_int_array;

	temp_int_array = (int *)malloc((2) * sizeof(int));
	if (data->store.len_stack_a > 1)
	{
		temp_int_array[0] = data->store.stack_a[0];
		temp_int_array[1] = data->store.stack_a[1];
		data->store.stack_a[0] = temp_int_array[1];
		data->store.stack_a[1] = temp_int_array[0];
		ft_putstr_fd("sa\n", 1);
		free(temp_int_array);
	}
	return ;
}

void	swap_b(t_swap *data)
{
	int	*temp_int_array;

	temp_int_array = (int *)malloc((2) * sizeof(int));
	if (data->store.len_stack_b > 1)
	{
		temp_int_array[0] = data->store.stack_a[0];
		temp_int_array[1] = data->store.stack_a[1];
		data->store.stack_b[0] = temp_int_array[1];
		data->store.stack_b[1] = temp_int_array[0];
		ft_putstr_fd("sb\n", 1);
		free(temp_int_array);
	}
	return ;
}

void	swap_ss(t_swap *data)
{
	swap_a(data);
	swap_b(data);
	return ;
}
