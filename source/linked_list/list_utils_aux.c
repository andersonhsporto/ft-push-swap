/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:56:10 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/10 00:26:42 by anhigo-s         ###   ########.fr       */
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
	while (index < (data->store.len_stack_a + 1))
	{
		lstadd_back_int(&info, lstnew_int(data->store.stack_a[index]));
		index++;
	}
	return (info);
}
