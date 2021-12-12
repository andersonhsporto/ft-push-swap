/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:56:10 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/11 21:14:35 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstdelete_int(t_sort **lst)
{
	t_sort	*index;
	t_sort	*temp;

	index = *lst;
	temp = NULL;
	while (index)
	{
		temp = index;
		index = index->next;
		free(temp);
	}
	lst = NULL;
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

void	printlist(t_sort *info)
{
	t_sort	*temp;

	temp = info;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			printf("%d \n", temp->content);
		else
			printf("%d \n", temp->content);
		temp = temp->next;
	}
	return ;
}

int	list_is_sorted(t_sort *info)
{
	t_sort	*temp;

	if (info == NULL)
		return (1);
	temp = info;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
