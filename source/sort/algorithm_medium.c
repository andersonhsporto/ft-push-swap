/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:37:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/17 22:29:44 by anhigo-s         ###   ########.fr       */
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
	while (i < 2)
	{
		move_fourths(&stk_a, &stk_b, -21, 10);
		i++;
	}
	printlist(stk_b);
}

void	move_fourths(t_sort **lst,	t_sort **lst_b, int min, int max)
{
	int		fourth_size;
	int		size_lst;
	t_sort	*tmp;

	tmp = *lst;
	fourth_size = lstsize_int(*lst) / 5;
	size_lst = lstsize_int(*lst);
	while (lstsize_int(*lst) > size_lst - fourth_size)
	{
		printf("SIZE = %d, min %d, max %d\n", lstsize_int(*lst), min, max);
		if (tmp->content >= min && tmp->content <= max)
			list_push(&(*lst), &(*lst_b), pb);
		list_rotate(&(*lst), ra);
		tmp = *lst;
	}
	return ;
}
