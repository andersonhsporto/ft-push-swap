/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 03:01:42 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/19 17:00:53 by anhigo-s         ###   ########.fr       */
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
	//printlist(stk_a);
	//list_rotate_reverse(&stk_a, 0);
	stk_b = NULL;
	while (i < data->group_size)
	{
		move_fourths(&stk_a, &stk_b, \
			data->merge.grp_min[i], data->merge.grp_max[i]);
		i++;
	}
	sort_stack(&stk_a, 0, data->max);
	push_main(&stk_a, &stk_b);
	printlist(stk_a);
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
	int			flag;
	t_sort		*tmp;

	tmp = *lst;
	size_lst = lstsize_int(*lst);
	flag = 0;
	if (!size)
		size = lstsize_int(*lst) / 5;
	while (lstsize_int(*lst) > size_lst - size)
	{
		flag = 0;
		if (tmp->content >= min && tmp->content <= max)
		{
			tmp = *lst;
			list_push(&(*lst), &(*lst_b), pb);
			if (lstsize_int((*lst_b)) > 1 && tmp->content < tmp->next->content)
			{
				list_rotate_reverse_rrr(&(*lst), &(*lst_b));
				flag = 1;
			}
		}
		if (flag == 0)
			list_rotate(&(*lst), ra);
		tmp = *lst;
	}
	return ;
}
