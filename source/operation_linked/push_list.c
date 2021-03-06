/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:17:51 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/10 21:04:14 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_push(t_sort **src, t_sort **dst, int status)
{
	t_sort	*temp;

	if (src != NULL)
	{
		temp = *src;
		*src = (*src)->next;
		temp->next = *dst;
		*dst = temp;
		if (status == pa)
			ft_putendl_fd("pa", 1);
		if (status == pb)
			ft_putendl_fd("pb", 1);
	}
	return ;
}
