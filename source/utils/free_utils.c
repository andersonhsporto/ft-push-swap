/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:04:02 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/30 00:57:37 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_swap *data)
{
	free(data->store.stack_a);
	data->store.stack_a = NULL;
	print_error("Error\n", EXIT_FAILURE);
	return ;
}

void	free_array(void **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	return ;
}
