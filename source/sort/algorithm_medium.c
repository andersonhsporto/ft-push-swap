/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:37:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/19 01:18:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_fourths(t_sort **lst,	t_sort **lst_b, int min, int max);
void	push_main(t_sort **dst, t_sort **src);

void	quick_test(t_swap *data)
{
	t_sort	*stk_a;
	t_sort	*stk_b;
	int i = 0;

	stk_a = array_to_list(data);
	stk_b = NULL;
	while (i < (data->store.len_stack_a / 2) - 2)
	{
		move_fourths(&stk_a, &stk_b, \
		data->merge.grp_min[i], data->merge.grp_max[i]);
		i++;
	}
	//printlist(stk_b);
	sort_stack(&stk_a, 0, data->max);
	push_main(&stk_a, &stk_b);
}

void	push_main(t_sort **dst, t_sort **src)
{
	while (*src != NULL)
	{
		list_push(&(*src), &(*dst), pa);
	}
	return ;
}

void	move_fourths(t_sort **lst,	t_sort **lst_b, int min, int max)
{
	static int	size;
	int			size_lst;
	t_sort		*tmp;

	tmp = *lst;
	size_lst = lstsize_int(*lst);
	if (!size)
		size = lstsize_int(*lst) / 5;
	while (lstsize_int(*lst) > size_lst - size)
	{
		if (tmp->content >= min && tmp->content <= max)
		{
			list_push(&(*lst), &(*lst_b), pb);
			if (lstsize_int((*lst_b)) > 1 && \
			(*lst_b)->content < (*lst_b)->next->content)
			{
				list_swap(*&(*lst_b), 0);
			}
		}
		list_rotate(&(*lst), ra);
		tmp = *lst;
	}
	return ;
}
