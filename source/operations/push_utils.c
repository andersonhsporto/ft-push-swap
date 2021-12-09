/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:12:24 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/09 14:37:48 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	temp_copy(t_swap *data, int stack);
void	del_stack_a(t_swap *data);
void	del_stack_b(t_swap *data);

void	move_stack_a(t_swap *data)
{
	int	index;

	if (data->store.len_stack_b == 0)
		return ;
	temp_copy(data, 1);
	free(data->store.stack_a);
	data->store.len_stack_a++;
	data->store.stack_a = (int *)ft_calloc(sizeof(int), \
	(data->store.len_stack_a));
	data->store.stack_a[0] = data->store.stack_b[0];
	index = 0;
	while (index < data->store.len_stack_a)
	{
		data->store.stack_a[index + 1] = data->store.temp_number[index];
		index++;
	}
	free(data->store.temp_number);
	del_stack_b(data);
	return ;
}

void	move_stack_b(t_swap *data)
{
	int	index;

	if (data->store.len_stack_a == 0)
		return ;
	temp_copy(data, 2);
	free(data->store.stack_b);
	data->store.stack_b = (int *)ft_calloc(sizeof(int), \
	(data->store.len_stack_b + 1));
	data->store.stack_b[0] = data->store.stack_a[0];
	index = 0;
	while (index < data->store.len_stack_b)
	{
		data->store.stack_b[index + 1] = data->store.temp_number[index];
		index++;
	}
	data->store.len_stack_b++;
	free(data->store.temp_number);
	del_stack_a(data);
	return ;
}

void	temp_copy(t_swap *data, int stack)
{
	int	index;
	int	size;

	if (stack == a_stack)
		size = data->store.len_stack_a;
	if (stack == b_stack)
		size = data->store.len_stack_b;
	data->store.temp_number = (int *)ft_calloc(sizeof(int), size);
	index = 0;
	while (index < size)
	{
		if (stack == a_stack)
			data->store.temp_number[index] = data->store.stack_a[index];
		if (stack == b_stack)
			data->store.temp_number[index] = data->store.stack_b[index];
		index++;
	}
	return ;
}

void	del_stack_a(t_swap *data)
{
	int	index;

	temp_copy(data, a_stack);
	free(data->store.stack_a);
	data->store.len_stack_a--;
	data->store.stack_a = (int *)ft_calloc(sizeof(int), \
	(data->store.len_stack_a));
	index = 0;
	while (index < data->store.len_stack_a)
	{
		data->store.stack_a[index] = data->store.temp_number[index + 1];
		index++;
	}
	free(data->store.temp_number);
	return ;
}

void	del_stack_b(t_swap *data)
{
	int	index;

	temp_copy(data, b_stack);
	free(data->store.stack_b);
	data->store.len_stack_b--;
	data->store.stack_b = (int *)ft_calloc(sizeof(int), \
	(data->store.len_stack_b));
	index = 0;
	while (index < data->store.len_stack_b)
	{
		data->store.stack_b[index] = data->store.temp_number[index + 1];
		index++;
	}
	free(data->store.temp_number);
	return ;
}
