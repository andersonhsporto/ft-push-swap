/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_scan_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/12 17:48:42 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sort	*array_to_list(t_swap *data)
{
	t_sort	*list;
	int		index;

	list = lstnew_int(data->store.stack_a[0]);
	index = 1;
	data->max = data->store.stack_a[0];
	while (index < (data->store.len_stack_a))
	{
		lstadd_back_int(&list, lstnew_int(data->store.stack_a[index]));
		if (data->max < data->store.stack_a[index])
		{
			data->max = data->store.stack_a[index];
		}
		index++;
	}
	scan_groups(data);
	free(data->store.stack_a);
	return (list);
}

int	find_min(t_sort *lst)
{
	int		min;
	t_sort	*tmp;

	tmp = lst;
	min = MAX_INT;
	while (tmp != NULL)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
		}
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_sort *lst)
{
	int		max;
	t_sort	*tmp;

	tmp = lst;
	max = INT_MIN;
	while (tmp != NULL)
	{
		if (max < tmp->content)
		{
			max = tmp->content;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	find_index(t_sort *lst, int number)
{
	t_sort	*tmp;
	int		index;

	tmp = lst;
	index = 0;
	while (tmp != NULL)
	{
		if (number == tmp->content)
		{
			break ;
		}
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int	lst_scan(t_sort *lst, int number)
{
	t_sort	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->content < number)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
