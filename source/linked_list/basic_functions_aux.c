/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:56:10 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/12 15:07:05 by anhigo-s         ###   ########.fr       */
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

int	list_is_sorted(t_sort *info, int status)
{
	t_sort	*temp;

	if (info == NULL)
		return (1);
	temp = info;
	while (temp->next != NULL)
	{
		if ((temp->content > temp->next->content) && (status == 1))
			return (0);
		if ((temp->content < temp->next->content) && (status == 2))
			return (0);
		temp = temp->next;
	}
	return (1);
}
