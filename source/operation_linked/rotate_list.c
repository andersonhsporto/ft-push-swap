/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:43:41 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/12 17:46:58 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_rotate(t_sort **src, int status)
{
	t_sort	*head;

	if (lstsize_int(*src) > 1)
	{
		head = *src;
		*src = (*src)->next;
		head->next = NULL;
		lstadd_back_int(src, head);
		if (status == ra)
			ft_putendl_fd("ra", 1);
		if (status == rb)
			ft_putendl_fd("rb", 1);
	}
	return ;
}
