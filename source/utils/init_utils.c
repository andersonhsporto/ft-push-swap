/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:25:54 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/02 02:55:29 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_fourth(t_swap	*data);

void	bubble_sort(int *tab, int size)
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
	while (i * i <= (size_t)nb)
	{
		if (i * i == (size_t)nb)
			return (i);
		i++;
	}
	return (i - 1);
}

void	scan_fourth(t_swap	*data)
{
	int		*sorted;
	size_t	size;
	int		i;
	int		j;

	sorted = array_dup(data);
	bubble_sort(sorted, data->store.len_stack_a);
	size = ft_sqrt(data->store.len_stack_a);
	data->number_group = size;
	data->merge.grp_max = (int *)malloc(sizeof(int) * (size + 1));
	data->merge.grp_max[size] = data->max;
	i = 0;
	j = 1;
	while (j < (int)size)
	{
		i = i + (data->store.len_stack_a / size);
		data->merge.grp_max[j] = sorted[i - 1];
		j++;
	}
	free(sorted);
}
