/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:37:35 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/27 03:43:57 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_int_vector(int *data, int size)
{
	int	*vector;
	int	i;

	vector = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		vector[i] = data[i];
		i++;
	}
	return (vector);
}

void	add_integer(int integer, int *vector, int *size)
{
	int	*temp_vector;
	int	i;

	temp_vector = copy_int_vector(vector, *size);
	free(vector);
	vector = (int *)malloc((*size + 1) * sizeof(int));
	vector[0] = integer;
	i = 1;
	while (i < (*size + 1))
	{
		vector[i] = temp_vector[i - 1];
		i++;
	}
	*size = i;
	free(temp_vector);
}

void	delete_integer(int *vector, int *size)
{
	int	*temp_vector;
	int	i;

	temp_vector = copy_int_vector(vector, *size);
	free(vector);
	vector = (int *)malloc((*size - 1) * sizeof(int));
	i = 0;
	while (i < (*size - 1))
	{
		vector[i] = temp_vector[i + 1];
		i++;
	}
	*size = i;
	free(temp_vector);
}

