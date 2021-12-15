/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:31:13 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/15 14:14:59 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_rotate_reverse(t_sort **info, int status)
{
	t_sort	*seclast;
	t_sort	*last;

	if (lstsize_int(*info) > 1)
	{
		last = *info;
		seclast = *info;
		while (last->next != NULL)
		{
			seclast = last;
			last = last->next;
		}
		seclast->next = NULL;
		lstadd_front_int(info, last);
		if (status == rra)
			ft_putendl_fd("rra", 1);
		if (status == rrb)
			ft_putendl_fd("rrb", 1);
	}
	return ;
}

void	list_rotate_reverse_rrr(t_sort **stack_a, t_sort **stack_b)
{
	list_rotate_reverse(stack_a, rrr);
	list_rotate_reverse(stack_b, rrr);
	ft_putendl_fd("rrr", 1);
}
