/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:31:13 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/12 17:45:36 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_rotate_reverse(t_sort **src, int status)
{
	t_sort	*seclast;
	t_sort	*last;

	if (lstsize_int(*src) > 1)
	{
		last = *src;
		seclast = *src;
		while (last->next != NULL)
		{
			seclast = last;
			last = last->next;
		}
		seclast->next = NULL;
		lstadd_front_int(src, last);
		if (status == rra)
			ft_putendl_fd("rra", 1);
		if (status == rrb)
			ft_putendl_fd("rrb", 1);
	}
	return ;
}
