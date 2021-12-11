/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:56:10 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/10 20:03:15 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstdelone_int(t_sort *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

void	lstclear_int(t_sort **lst, void (*del)(void *))
{
	t_sort	*i;

	while (*lst)
	{
		i = (*lst)->next;
		lstdelone_int(*lst, del);
		*lst = i;
	}
	lst = 0;
}

t_sort	*array_to_list(t_swap *data)
{
	t_sort	*info;
	int		index;

	info = lstnew_int(data->store.stack_a[0]);
	index = 1;
	while (index < (data->store.len_stack_a))
	{
		lstadd_back_int(&info, lstnew_int(data->store.stack_a[index]));
		index++;
	}
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
