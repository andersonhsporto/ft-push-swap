/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_scan_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/12 15:04:01 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sort	*lst_dup_int(t_sort *info)
{
	t_sort	*copy;

	if (info == NULL)
		return (NULL);
	copy = malloc(sizeof(t_sort));
	copy->content = info->content;
	copy->next = lst_dup_int(info->next);
	return (copy);
}

int	find_median(t_sort *info)
{
	t_sort	*temp_list;
	t_sort	*node;
	int		index;

	temp_list = lst_dup_int(info);
	list_bubble_sort(&temp_list);
	node = NULL;
	index = 0;
	while (index < (lstsize_int(info) / 2))
	{
		node = temp_list;
		temp_list = temp_list->next;
		index++;
	}
	if ((lstsize_int(info) % 2) != 0)
		index = node->next->content;
	if ((lstsize_int(info) % 2) == 0)
		index = ((node->content + node->next->content) / 2);
	lstdelete_int(&temp_list);
	return (index);
}

void	list_bubble_sort(t_sort **info)
{
	t_sort	*newlist;
	t_sort	*index;
	int		temp;

	newlist = *info;
	index = NULL;
	temp = 0;
	if (info == NULL)
		return ;
	while (newlist != NULL)
	{
		index = newlist->next;
		while (index != NULL)
		{
			if (newlist->content > index->content)
			{
				temp = newlist->content;
				newlist->content = index->content;
				index->content = temp;
			}
			index = index->next;
		}
		newlist = newlist->next;
	}
}

void	scan_list(t_sort *info, t_swap *data)
{
	t_sort	*temp;

	if (info == NULL)
		return ;
	temp = info;
	data->max = temp->content;
	data->min = temp->content;
	while (temp->next != NULL)
	{
		if (temp->content > data->max)
			data->max = temp->content;
		if (temp->content < data->min)
			data->min = temp->content;
		temp = temp->next;
	}
	return ;
}

t_sort	*array_to_list(t_swap *data)
{
	t_sort	*info;
	int		index;

	info = lstnew_int(data->store.stack_a[0]);
	index = 1;
	data->min = data->store.stack_a[0];
	data->max = data->store.stack_a[0];
	while (index < (data->store.len_stack_a))
	{
		lstadd_back_int(&info, lstnew_int(data->store.stack_a[index]));
		if (data->max > data->store.stack_a[index])
			data->max = data->store.stack_a[index];
		if (data->min < data->store.stack_a[index])
			data->min = data->store.stack_a[index];
		index++;
	}
	data->median = find_median(info);
	free(data->store.stack_a);
	free(data->store.stack_b);
	return (info);
}
