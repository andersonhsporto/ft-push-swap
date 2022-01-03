/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:08:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/03 00:21:08 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_sort **list, int status);
void	sort_cont(t_sort **list, int status);
void	sort_five(t_swap *data);
void	push_min_top(t_sort **dst);

void	simple_algo(t_swap *data)
{
	data->stk_a = array_to_list(data);
	if (data->args.argc <= 3)
		sort_three(&data->stk_a, e_stack_a);
	if (data->args.argc > 3)
		sort_five(data);
	lstdelete_int(data->stk_a);
	free(data->grp_max);
	return ;
}

void	sort_three(t_sort **list, int status)
{
	t_sort	*tmp;

	tmp = *list;
	if (lstsize_int(*list) == 2 && list_is_sorted(*list, 2))
		list_swap((*list), status);
	while (list_is_sorted(*list, 1) == 0)
	{
		if (tmp->content > tmp->next->content && \
			tmp->next->content < tmp->next->next->content && \
			tmp->next->next->content > tmp->content)
			list_swap(*&(*list), status);
		else if (tmp->content > tmp->next->content && \
		tmp->next->content > tmp->next->next->content && \
		tmp->next->next->content < tmp->next->content)
		{
			list_swap(*&(*list), status);
			list_rotate_reverse(&(*list), status);
		}
		sort_cont(&(*list), status);
	}
	return ;
}

void	sort_cont(t_sort **list, int status)
{
	t_sort	*tmp;

	tmp = *list;
	if (tmp->content > tmp->next->content && \
		tmp->content > tmp->next->next->content && \
		tmp->next->content < tmp->next->next->content)
		list_rotate(&(*list), status);
	else if (tmp->content < tmp->next->content && \
			tmp->next->content > tmp->next->next->content && \
			tmp->next->next->content > tmp->content)
	{
		list_swap(*list, status);
		list_rotate(&(*list), status);
	}
	else if (tmp->content < tmp->next->content && \
			tmp->content > tmp->next->next->content && \
			tmp->next->content > tmp->content)
	{
		list_rotate_reverse(&(*list), status);
	}
	return ;
}

void	sort_five(t_swap *data)
{
	t_sort	*stk_b;

	stk_b = NULL;
	while (!list_is_sorted(data->stk_a, 1))
	{
		while (lstsize_int(data->stk_a) > 3)
		{
			push_min_top(&data->stk_a);
			list_push(&data->stk_a, &stk_b, pb);
		}
		sort_three(&data->stk_a, e_stack_a);
		while (stk_b != NULL)
		{
			list_push(&stk_b, &data->stk_a, pa);
		}
	}
	return ;
}

void	push_min_top(t_sort **dst)
{
	int	index;

	index = find_index(*dst, find_min(*dst));
	if (index < (lstsize_int(*dst) / 2))
	{
		while (index > 0)
		{
			index--;
			list_rotate(&(*dst), ra);
		}
	}
	else
	{
		while (index < (lstsize_int(*dst)))
		{
			index++;
			list_rotate_reverse(&(*dst), ra);
		}
	}
}
