/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:37:35 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/27 15:47:28 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_int_vector(int *vector, int size)
{
	int	*copy;
	int	i;

	copy = (int *)malloc((size) * sizeof(int));
	i = 0;
	while (i < (size))
	{
		copy[i] = vector[i];
		i++;
	}
	return (copy);
}

void	add_integer(int integer, int **vector, int size)
{
	int	*temp_vector;
	int	i;

	if (size == 1)
	{
		*vector[0] = integer;
		return ;
	}
	temp_vector = copy_int_vector(*vector, size);
	free(*vector);
	*vector = NULL;
	*vector = (int *)malloc((size + 1) * sizeof(int));
	*vector[0] = integer;
	i = 0;
	printf("%d", size);
	while (i < (size + 1))
	{
		*vector[i + 1] = temp_vector[i];
		i++;
	}
	free(temp_vector);
	temp_vector = NULL;
}

void	delete_integer(int **vector, int size)
{
	int	*temp_vector;
	int	i;

	temp_vector = copy_int_vector(*vector, size);
	free(*vector);
	*vector = NULL;
	*vector = (int *)malloc((size - 1) * sizeof(int));
	i = 0;
	while (i < (size - 2))
	{
		*vector[i] = temp_vector[i + 1];
		i++;
	}
	free(temp_vector);
	temp_vector = NULL;
	return ;
}

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
		delete_integer(&data->store.stack_b,
			data->store.len_stack_b);
	}
	return ;
}
