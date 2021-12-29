/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 03:01:42 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/29 16:46:44 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_fourths(t_swap *data,	t_sort **lst_b, int max);
void	algo_b(t_sort **dst);

void	quick_test(t_swap *data)
{
	t_sort	*stk_b;
	int		index;

	data->stk_a = array_to_list(data);
	stk_b = NULL;
	index = 1;
	while (!list_is_sorted(data->stk_a, 1))
	{
		while (index < ft_sqrt(data->store.len_stack_a))
		{
			printf("%d number\n", data->size);
			move_fourths(data, &stk_b, data->merge.grp_max[index]);
			index++;
		}
		break ;
		while (stk_b != NULL)
		{
			algo_b(&stk_b);
			list_push(&stk_b, &data->stk_a, pa);
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

void	move_fourths(t_swap *data,	t_sort **lst_b, int max)
{
	static int	size;
	int			size_lst;
	int			flag;
	t_sort		*tmp;

	tmp = data->stk_a;
	size_lst = lstsize_int(data->stk_a);
	flag = 0;
	if (!size)
		size = data->store.len_stack_a / ft_sqrt(data->store.len_stack_a);
	while (lstsize_int(data->stk_a) < (size_lst - size))
	{
		flag = 0;
		if (tmp->content <= max)
		{
			list_push(&(data->stk_a), &(*lst_b), pb);
		}
		else
		{
			printf("%d = lstsize_int(data->stk_a)", lstsize_int(data->stk_a));
			printf(" %d = size_lst", size_lst);
			printf(" %d = size\n", size);
			list_rotate(&(data->stk_a), ra);
		}
		tmp = data->stk_a;
	}
	return ;
}
