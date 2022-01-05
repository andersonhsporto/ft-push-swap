/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:43:41 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/04 23:17:51 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_rotate(t_sort **info, int status)
{
	t_sort	*head;

	if (lstsize_int(*info) > 1)
	{
		head = *info;
		*info = (*info)->next;
		head->next = NULL;
		lstadd_back_int(info, head);
		if (status == ra)
			ft_putendl_fd("ra", 1);
		if (status == rb)
			ft_putendl_fd("rb", 1);
	}
	return ;
}
