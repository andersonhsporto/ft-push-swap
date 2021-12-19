/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilogy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:08:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/18 23:36:47 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_cont(t_sort **list, int status);
void	sort_three(t_sort **list, int status);
void	rev_sort_three(t_sort **list, int status);
void	rev_sort_cont(t_sort **list, int status);

void	simple_algo(t_swap *data)
{
	t_sort	*stack_a;

	stack_a = array_to_list(data);
	sort_three(&stack_a, e_stack_a);
	lstdelete_int(stack_a);
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

void	rev_sort_three(t_sort **list, int status)
{
	t_sort	*tmp;

	tmp = *list;
	if (lstsize_int(*list) == 2 && list_is_sorted(*list, 1))
		list_swap(*list, status);
	while (!list_is_sorted(*list, 2))
	{
		if (tmp->content > tmp->next->content && \
		tmp->next->content < tmp->next->next->content && \
		tmp->next->next->content > tmp->content)
			list_rotate_reverse(&(*list), status);
		else if (tmp->content < tmp->next->content && \
		tmp->next->content < tmp->next->next->content && \
		tmp->next->next->content > tmp->next->content)
		{
			list_swap(*list, status);
			list_rotate_reverse(&(*list), status);
		}
		rev_sort_cont(&(*list), status);
	}
	return ;
}

void	rev_sort_cont(t_sort **list, int status)
{
	t_sort	*tmp;

	tmp = *list;
	if (tmp->content > tmp->next->content && \
		tmp->content > tmp->next->next->content && \
		tmp->next->content < tmp->next->next->content)
	{
		list_rotate_reverse(&(*list), status);
		list_swap(*list, status);
	}
	else if (tmp->content < tmp->next->content && \
			tmp->next->content > tmp->next->next->content && \
			tmp->next->next->content > tmp->content)
	{
		list_rotate(&(*list), status);
	}
	else if (tmp->content < tmp->next->content && \
			tmp->content > tmp->next->next->content && \
			tmp->next->content > tmp->content)
	{
		list_swap(*list, status);
	}
	return ;
}
