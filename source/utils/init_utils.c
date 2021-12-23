/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:25:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/23 01:27:43 by anhigo-s         ###   ########.fr       */
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
	scan_fourth(data);
	return ;
}

void	scan_fourth(t_swap	*data)
{
	int	index;
	int i = 1;
	int j = 1;
	int	*dup;

	dup = array_dup(data);
	ft_sort_int_tab(dup, data->store.len_stack_a);
	index = data->store.len_stack_a / 5;
	data->group_size = data->store.len_stack_a / 5;
	data->merge.grp_min = (int *)malloc(sizeof(int) * index);
	data->merge.grp_max = (int *)malloc(sizeof(int) * index);
	data->merge.grp_min[0] = dup[0];
	data->merge.grp_max[0] = dup[index - 1];
	while (i < 5)
	{
		data->merge.grp_min[j] = dup[index * i];
		i++;
		data->merge.grp_max[j] = dup[(index * i) - 1];
		j++;
	}
	free(dup);
}

void	init_data(t_swap *data, int argc, char **argv)
{
	data->args.argc = argc;
	data->args.argv = argv;
	data->store.len_stack_b = 0;
	data->store.stack_b = (int *)malloc(1 * sizeof(int));
	return ;
}

// void	scan_fourth(t_swap	*data)
// {
// 	int	index;
// 	int	*dup;

// 	dup = array_dup(data);
// 	ft_sort_int_tab(dup, data->store.len_stack_a);
// 	index = data->store.len_stack_a / 5;
// 	data->merge.fourth_fst.min = dup[0];
// 	data->merge.fourth_fst.max = dup[index - 1];
// 	data->merge.fourth_sec.min = dup[index];
// 	data->merge.fourth_sec.max = dup[(index * 2) - 1];
// 	data->merge.fourth_trd.min = dup[(index * 2)];
// 	data->merge.fourth_trd.max = dup[(index * 3) - 1];
// 	data->merge.fourth_fth.min = dup[(index * 3)];
// 	data->merge.fourth_fth.max = dup[(index * 4) - 1];
// 	data->merge.fourth_fiv.min = dup[(index * 4)];
// 	data->merge.fourth_fiv.max = dup[(index * 5) - 1];
// 	// printf("%d %d ", data->merge.fourth_fst.min, data->merge.fourth_fst.max);
// 	// printf("%d %d ", data->merge.fourth_sec.min, data->merge.fourth_sec.max);
// 	// printf("%d %d ", data->merge.fourth_trd.min, data->merge.fourth_trd.max);
// 	// printf("%d %d ", data->merge.fourth_fth.min, data->merge.fourth_fth.max);
// 	// printf("%d %d\n", data->merge.fourth_fiv.min, data->merge.fourth_fiv.max);
// 	free(dup);
// }

