/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:43:41 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/10 18:27:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_rotate(t_sort **info, int status)
{
	t_sort	*head;
	t_sort	*temp;

	if (lstsize_int(*info) > 1)
	{
		temp = *info;
		*info = (*info)->next;
		temp->next = NULL;
		lstadd_back_int(info, temp);
		if (status == ra)
			ft_putendl_fd("ra", 1);
		if (status == rb)
			ft_putendl_fd("rb", 1);
	}
	return ;
}

void	list_rotate_rr(t_sort **stack_a, t_sort **stack_b)
{
	list_rotate(stack_a, rr);
	list_rotate(stack_b, rr);
	ft_putendl_fd("rr", 1);
	return ;
}
