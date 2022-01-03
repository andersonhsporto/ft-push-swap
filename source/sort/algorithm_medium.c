/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 03:01:42 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/03 00:02:05 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_fourths(t_swap *data,	t_sort **lst_b, int max);
void	push_max_top(t_sort **dst);

void	merge_sort(t_swap *data)
{
	t_sort	*stk_b;
	size_t	index;

	data->stk_a = array_to_list(data);
	stk_b = NULL;
	index = 1;
	while (!list_is_sorted(data->stk_a, 1))
	{
		while (index < (ft_sqrt(data->store.len_stack_a) + 1))
		{
			move_fourths(data, &stk_b, data->grp_max[index]);
			index++;
		}
		while (stk_b != NULL)
		{
			push_max_top(&stk_b);
			list_push(&stk_b, &data->stk_a, pa);
		}
	}
	free(data->grp_max);
	lstdelete_int(data->stk_a);
}

void	move_fourths(t_swap *data,	t_sort **lst_b, int max)
{
	static int	size;
	t_sort		*tmp;

	tmp = data->stk_a;
	if (!size)
		size = data->store.len_stack_a / ft_sqrt(data->store.len_stack_a);
	while (lst_scan(data->stk_a, max))
	{
		if (tmp->content <= max)
		{
			list_push(&(data->stk_a), &(*lst_b), pb);
		}
		else
		{
			list_rotate(&(data->stk_a), ra);
		}
		tmp = data->stk_a;
	}
	return ;
}

void	push_max_top(t_sort **dst)
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
