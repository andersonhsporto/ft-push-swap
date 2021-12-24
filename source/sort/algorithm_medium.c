/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 03:01:42 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/23 21:48:29 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_fourths(t_sort **lst,	t_sort **lst_b, int min, int max);
void	algo_b(t_sort **dst);

void	quick_test(t_swap *data)
{
	t_sort	*stk_a;
	t_sort	*stk_b;
	int		index;

	stk_a = array_to_list(data);
	stk_b = NULL;
	index = 0;
	while (!list_is_sorted(stk_a, 1))
	{
		while (index < data->number_group)
		{
			move_fourths(&stk_a, &stk_b, \
				data->merge.grp_min[index], data->merge.grp_max[index]);
			index++;
		}
		while (stk_b != NULL)
		{
			algo_b(&stk_b);
			list_push(&stk_b, &stk_a, pa);
		}
	}
}

void	algo_b(t_sort **dst)
{
	int	index;

	index = find_index(*dst, find_max(*dst));
	if (index < (lstsize_int(*dst) / 2))
	{
		while (index > 0)
		{
			index--;
			list_rotate(&(*dst), 1);
		}
	}
	else
	{
		while (index < (lstsize_int(*dst)))
		{
			index++;
			list_rotate_reverse(&(*dst), 1);
		}
	}
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
		size = lstsize_int(*lst) / 10;
	while (lstsize_int(*lst) > size_lst - size)
	{
		flag = 0;
		if (tmp->content >= min && tmp->content <= max)
		{
			list_push(&(*lst), &(*lst_b), pb);
		}
		else
		{
			printf("min = %d, max = %d\n", min, max);
			list_rotate(&(*lst), ra);
		}
		tmp = *lst;
	}
	return ;
}
