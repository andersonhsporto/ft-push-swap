/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 03:01:42 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/24 00:09:03 by anhigo-s         ###   ########.fr       */
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
	index = 0;
	while (!list_is_sorted(data->stk_a, 1))
	{
		while (index < data->size)
		{
			printf("%d number\n", data->size);
			move_fourths(data, &stk_b, data->merge.grp_max[index]);
			//break ;
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
		size = data->number_group;
	while (lstsize_int(data->stk_a) > size_lst - size)
	{
		flag = 0;
		if (tmp->content <= max)
		{
			list_push(&(data->stk_a), &(*lst_b), pb);
		}
		else
		{
			printf("max = %d %d > %d content = %d\n", max, lstsize_int(data->stk_a), size_lst - size, tmp->content);
			list_rotate(&(data->stk_a), ra);
		}
		tmp = data->stk_a;
	}
	return ;
}
