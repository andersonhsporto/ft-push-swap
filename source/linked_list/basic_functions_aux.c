/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:56:10 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/13 15:57:23 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstdelete_int(t_sort *lst)
{
	if (lst->next)
		lstdelete_int(lst->next);
	free(lst);
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
