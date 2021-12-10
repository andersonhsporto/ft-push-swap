/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:56:10 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/09 23:16:54 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sort	*lstnew_int(int content)
{
	t_sort	*element;

	element = malloc(sizeof(t_list));
	if (element)
	{
		element->content = content;
		element->next = (0);
		return (element);
	}
	return (0);
}

void	lstadd_front_int(t_sort **lst, t_sort *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	lstsize_int(t_sort *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_sort	*lstlast_int(t_sort *lst)
{
	if (lst)
	{
		while (lst->next != 0)
		{
			lst = lst->next;
		}
		return (lst);
	}
	return (0);
}

void	lstadd_back_int(t_sort **lst, t_sort *new)
{
	t_sort	*i;

	if (*lst)
	{
		i = lstlast_int(*lst);
		i->next = new;
	}
	else
	{
		*lst = new;
	}
}
