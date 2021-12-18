/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:37:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/18 02:00:11 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_fourths(t_sort **lst,	t_sort **lst_b, int min, int max);

void	quick_test(t_swap *data)
{
	t_sort	*stk_a;
	t_sort	*stk_b;
	int i = 0;

	stk_a = array_to_list(data);
	stk_b = NULL;
	while (i < (data->store.len_stack_a / 2) - 2)
	{
		//printf("%d %d \n", data->merge.grp_min[i], data->merge.grp_max[i]);
		move_fourths(&stk_a, &stk_b, data->merge.grp_min[i], data->merge.grp_max[i]);
		i++;
	}
	sort_stack(&stk_a, 0);
	//printlist(stk_a);
	//reverse_sort_stack(&stk_b, 1);
	while (stk_b != NULL)
	{
		list_push(&stk_b, &stk_a, pa);
	}
	// printlist(stk_a);
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
			//printf(">> cotent = %d \n", tmp->content);
			list_push(&(*lst), &(*lst_b), pb);
		}
		list_rotate(&(*lst), ra);
		tmp = *lst;
	}
	return ;
}
