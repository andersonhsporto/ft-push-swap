/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 03:01:42 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/30 02:26:10 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_fourths(t_swap *data,	t_sort **lst_b, int max);
int		lst_find(t_sort *lst, int nb);
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
		while (index < (ft_sqrt(data->store.len_stack_a) + 1))
		{
			//printf("%d number\n", ft_sqrt(data->store.len_stack_a));
			move_fourths(data, &stk_b, data->merge.grp_max[index]);
			//printf("%d \n", data->merge.grp_max[index]);
			index++;
		}
		//break ;
		while (stk_b != NULL)
		{
			algo_b(&stk_b);
			list_push(&stk_b, &data->stk_a, pa);
		}
		//break ;
		//printlist(data->stk_a);
	}
	free(data->merge.grp_max);
	lstdelete_int(data->stk_a);
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
	// if (max == data->max)
	// 	size -= 1;
	while (lst_find(data->stk_a, max))
	{
		flag = 0;
		if (tmp->content <= max)
		{
			list_push(&(data->stk_a), &(*lst_b), pb);
		}
		else
		{
			// printf("%d = lstsize_int(data->stk_a)", lstsize_int(data->stk_a));
			// printf(" %d = size_lst", size_lst);
			// printf(" %d = size ", size);
			// printf(" MAX ==%d\n", max);
			list_rotate(&(data->stk_a), ra);
		}
		tmp = data->stk_a;
	}
	return ;
}

int	lst_find(t_sort *lst, int nb)
{
	t_sort	*temp;

	temp = lst;
	while (temp != NULL)
	{
		if (temp->content < nb)
			return (1);
		temp = temp->next;
	}
	return (0);
}
