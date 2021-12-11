/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:47:20 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/11 03:10:38 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	least_worst_algo(t_swap *data)
{
	t_sort	*stack_a;
	t_sort	*stack_b;

	stack_a = array_to_list(data);
	scan_list(stack_a, data);
	while (i < 4)
	{
		if (stack_a->content = data->median)
		{
			list_push(&stack_a, &stack_b, pa);
			scan_list(stack_a, data);
		}
		list_rotate(&stack_a, ra);
		i++;
	}
	while (stack_b != NULL)
	{
		list_push(&stack_b, &stack_a, pb);
	}
	return ;
}

void	worst_algo(t_swap *data)
{
	t_sort	*stack_a;
	t_sort	*stack_b;

	stack_a = array_to_list(data);
	scan_list(stack_a, data);
	while (stack_a != NULL)
	{
		if (data->min == stack_a->content)
		{
			list_push(&stack_a, &stack_b, pa);
			scan_list(stack_a, data);
		}
		list_rotate(&stack_a, ra);
	}
	while (stack_b != NULL)
	{
		list_push(&stack_b, &stack_a, pb);
	}
	return ;
}
