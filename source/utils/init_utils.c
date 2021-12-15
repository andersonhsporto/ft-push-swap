/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:25:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/14 22:50:59 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	count;
	int	comp;
	int	temp;

	count = 0;
	while (count < size)
	{
		comp = count + 1;
		while (comp < size)
		{
			if (tab[count] > tab[comp])
			{
				temp = tab[count];
				tab[count] = tab[comp];
				tab[comp] = temp;
			}
			comp++;
		}
		count++;
	}
}

int	*array_dup(t_swap *data)
{
	int	*temp;
	int	i;

	temp = (int *)malloc(sizeof(int *) * data->store.len_stack_a);
	i = 0;
	while (i < data->store.len_stack_a)
	{
		temp[i] = data->store.stack_a[i];
		i++;
	}
	return (temp);
}

void	scan_median(t_swap *data)
{
	int	*temp;

	temp = array_dup(data);
	ft_sort_int_tab(temp, data->store.len_stack_a);
	data->median_index = 0;
	if (data->store.len_stack_a % 2 == 0)
		data->median = (temp[(data->store.len_stack_a / 2) - 1]);
	if (data->store.len_stack_a % 2 != 0)
		data->median = (temp[data->store.len_stack_a / 2]);
	while (temp[data->median_index] < data->median)
	{
		data->median_index++;
	}
	return ;
}

void	init_data(t_swap *data, int argc, char **argv)
{
	data->args.argc = argc;
	data->args.argv = argv;
	data->store.len_stack_b = 0;
	data->store.stack_b = (int *)malloc(1 * sizeof(int));
	return ;
}
