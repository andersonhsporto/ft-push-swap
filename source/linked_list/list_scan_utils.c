/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_scan_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/29 15:36:44 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (data->max < data->store.stack_a[index])
			data->max = data->store.stack_a[index];
		if (data->min > data->store.stack_a[index])
			data->min = data->store.stack_a[index];
		index++;
	}
	scan_fourth(data);
	free(data->store.stack_a);
	free(data->store.stack_b);
	return (info);
}
