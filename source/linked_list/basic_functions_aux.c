/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:56:10 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/12 17:48:23 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstdelete_int(t_sort *lst)
{
	if (lst->next)
	{
		lstdelete_int(lst->next);
	}
	free(lst);
}

int	list_is_sorted(t_sort *src, int status)
{
	t_sort	*temp;

	if (src == NULL)
		return (1);
	temp = src;
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
