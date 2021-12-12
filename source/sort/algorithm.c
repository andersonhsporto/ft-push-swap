/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:47:20 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/11 23:10:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_algo(t_swap *data)
{
	t_sort	*stack_a;
	t_sort	*stack_b;

	stack_a = array_to_list(data);
	while (!list_is_sorted(stack_a))
	{
		list_rotate(&stack_a, ra);
		list_rotate(&stack_a, ra);
		list_swap(stack_a, sa);
	}
	return ;
}

void	worst_algo(t_swap *data)
{
	t_sort	*stack_a;
	t_sort	*stack_b;

	stack_a = array_to_list(data);
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

void	sort_stack(t_sort *list)
{
	t_sort	*temp;
	int		size;
	int		status;

	size = lstsize_int(temp);
	status = 0;
	temp = lst_dup_int(list);
	while (list_is_sorted(temp) == 0)
	{
		if (temp->content > temp->next->content && temp->content < \
		temp->next->next->content)
		{
			list_swap(temp, sa);
		}
		if (temp->content > temp->next->content && temp->content > \
		temp->next->next->content)
		{
			list_swap(temp, sa);
			list_rotate(&temp, ra);
		}
		if (temp->content < temp->next->content)
		{
			list_rotate_reverse(&temp, rra);
		}
	}
	return ;
}

void	least_worst_algo(t_swap *data)
{
	t_sort	*stack_a;
	t_sort	*stack_b;
	int		size;

	stack_a = array_to_list(data);
	sort_stack(stack_a);
	// while (lstsize_int(stack_b) != size / 2)
	// {
	// 	if (stack_a->content < data->median)
	// 	{
	// 		list_push(&stack_a, &stack_b, pb);
	// 		sort_stack(stack_a);
	// 	}
	// 	//printf("%d size = %d\n", stack_a->content, lstsize_int(stack_a));
	// 	list_rotate(&stack_a, ra);
	// }
	return ;
}
