/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:37:35 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/25 03:16:50 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_number(int *array, int size)
{
	int	*temp_interger;
	int	i;

	temp_interger = (int *)malloc((size) * sizeof(int));
	i = 0;
	while (i < size)
	{
		temp_interger[i] = array[i];
		i++;
	}
	free(array);
	return (temp_interger);
}

void	del_number(int *array, int size)
{
	int	*temp_interger;
	int	i;

	temp_interger = copy_number(array, size);
	array = (int *)malloc((size - 1) * sizeof(int));
	i = 0;
	while (i < (size - 1))
	{
		array[i] = temp_interger[i + 1];
		i++;
	}
	size = i;
	free(temp_interger);
	return ;
}

void	add_number(int *array, int size, int new_number)
{
	int	*temp_interger;
	int	i;

	temp_interger = copy_number(array, size);
	array = (int *)malloc((size - 1)
			* sizeof(int));
	array[0] = new_number;
	i = 1;
	while (i < (size - 1))
	{
		array[i] = temp_interger[i - 1];
		i++;
	}
	size = i;
	free(temp_interger);
	return ;
}

void	push_a(t_swap *data)
{
	int	temp_int;

	temp_int = data->store.stack_a[0];
	del_number(data->store.stack_a, data->store.len_stack_a);
	add_number(data->store.stack_b, data->store.len_stack_b,
		temp_int);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_swap *data)
{
	int	temp_int;

	temp_int = data->store.stack_b[0];
	del_number(data->store.stack_b, data->store.len_stack_b);
	add_number(data->store.stack_a, data->store.len_stack_a,
		temp_int);
	ft_putstr_fd("pb\n", 1);
}
