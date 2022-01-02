/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilogy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:08:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/02 19:07:06 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_cont(t_sort **list, int status);
void	sort_three(t_sort **list, int status);

void	simple_algo(t_swap *data)
{
	data->stk_a = array_to_list(data);
	if (data->args.argc <= 3)
		sort_three(&data->stk_a, e_stack_a);
	if (data->args.argc > 3)
		sort_five(data);
	//printlist(data->stk_a);
	lstdelete_int(data->stk_a);
	free(data->merge.grp_max); // verificar !!
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

int	find_min(t_sort *lst)
{
	int		min;
	t_sort	*tmp;

	tmp = lst;
	min = MAX_INT;
	while (tmp != NULL)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
		}
		tmp = tmp->next;
	}
	return (min);
}

void	sort_five(t_swap *data)
{
	t_sort	*stk_b;
	int		i;

	stk_b = NULL;
	i = 0;
	while (!list_is_sorted(data->stk_a, 1))
	{
		while (lstsize_int(data->stk_a) > 3)
		{
			algo_a(&data->stk_a);
			list_push(&data->stk_a, &stk_b, pb);
			i++;
		}
		sort_three(&data->stk_a, e_stack_a);
		while (stk_b != NULL)
		{
			list_push(&stk_b, &data->stk_a, pa);
		}
	}
	//printlist(data->stk_a);
	//ft_putstr_fd("pb\npa\n", 1);
	return ;
}

void	algo_a(t_sort **dst)
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