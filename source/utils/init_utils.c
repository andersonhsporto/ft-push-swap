/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:25:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/30 01:44:26 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_fourth(t_swap	*data);

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
		data->median = ((temp[(data->store.len_stack_a - 1) / 2] + temp[(data->store.len_stack_a / 2)]) / 2);
	if (data->store.len_stack_a % 2 != 0)
		data->median = (temp[data->store.len_stack_a / 2]);
	while (temp[data->median_index] < data->median)
	{
		data->median_index++;
	}
	free(temp);
	temp = NULL;
	//scan_fourth(data);
	return ;
}

// void	scan_fourth(t_swap	*data)
// {
// 	int	index;
// 	int i = 1;
// 	int j = 1;
// 	int	*dup;

// 	dup = array_dup(data);
// 	ft_sort_int_tab(dup, data->store.len_stack_a);
// 	index = data->store.len_stack_a / 10;
// 	data->size = data->store.len_stack_a / 10;
// 	data->merge.grp_min = (int *)malloc(sizeof(int) * index);
// 	data->merge.grp_max = (int *)malloc(sizeof(int) * index);
// 	data->merge.grp_min[0] = dup[0];
// 	data->merge.grp_max[0] = dup[index - 1];
// 	while (i < 10)
// 	{
// 		data->merge.grp_min[j] = dup[index * i];
// 		i++;
// 		data->merge.grp_max[j] = dup[(index * i) - 1];
// 		j++;
// 	}
// 	free(dup);
// }

void	init_data(t_swap *data, int argc, char **argv)
{
	data->args.argc = argc;
	data->args.argv = argv;
	data->store.len_stack_b = 0;
	data->store.stack_b = (int *)malloc(1 * sizeof(int));
	return ;
}

size_t	ft_sqrt(int nb)
{
	size_t	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

void	scan_fourth(t_swap	*data)
{
	int		*dup;
	int		i = 0;
	int 	j = 1;
	size_t	size;

	dup = array_dup(data);
	ft_sort_int_tab(dup, data->store.len_stack_a);
	size = ft_sqrt(data->store.len_stack_a);
	data->number_group = size;
	data->merge.grp_max = (int *)malloc(sizeof(int) * (size));
	data->merge.grp_max[size] = data->max;
	while (j < size)
	{
		i = i + (data->store.len_stack_a / size);
		data->merge.grp_max[j] = dup[i - 1];
		//printf("%d = i, %d = (data->store.len_stack_a / size), %d == size\n", i, (data->store.len_stack_a / size), data->merge.grp_max[j]);
		j++;
	}
	free(dup);
}
