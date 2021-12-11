/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_scan_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/11 03:02:22 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midean(t_sort *info)
{
	t_sort	*temp;
	int		size;
	int		index;

	temp = info;
	size = lstsize_int(info);
	index = 0;
	size = size / 2;
	while (index < size)
	{
		temp = temp->next;
		index++;
	}
	return (temp->content);
}

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

void	list_bubble_sort(t_sort **info)
{
	t_sort	*newlist;
	t_sort	*index;
	int		temp;

	newlist = info;
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
