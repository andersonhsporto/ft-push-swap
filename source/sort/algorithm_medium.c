/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 03:01:42 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/22 22:55:41 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_median(t_sort **dst, t_sort **src, t_swap *data);
void	push_main(t_sort **dst, t_sort **src);

void	quick_test(t_swap *data)
{
	t_sort	*stk_a;
	t_sort	*stk_b;

	stk_a = array_to_list(data);
	stk_b = NULL;
	move_median(&stk_b, &stk_a, data);
	while (!list_is_sorted(stk_a, 1) && !list_is_sorted(stk_b, 2))
	{
	}
	push_main(&stk_a, &stk_b);
	//printlist(stk_a);
}

void	move_median(t_sort **dst, t_sort **src, t_swap *data)
{
	t_sort	*tmp;
	int		size_src;

	tmp = *src;
	size_src = lstsize_int(*src) / 2;
	while (lstsize_int(*dst) != size_src)
	{
		if (tmp->content < data->median)
			list_push(&(*src), &(*dst), pb);
		else
			list_rotate(&(*src), ra);
		tmp = *src;
	}
}

void	push_main(t_sort **dst, t_sort **src)
{
	while (*src != NULL)
	{
		list_push(&(*src), &(*dst), pa);
	}
	return ;
}
