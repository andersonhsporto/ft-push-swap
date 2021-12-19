/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:47:20 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/19 01:12:48 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	worst_algo(t_swap *data)
// {
// 	t_sort	*stack_a;
// 	t_sort	*stack_b;

// 	stack_a = array_to_list(data);
// 	while (stack_a != NULL)
// 	{
// 		if (data->min == stack_a->content)
// 		{
// 			list_push(&stack_a, &stack_b, pa);
// 			scan_list(stack_a, data);
// 		}
// 		list_rotate(&stack_a, ra);
// 	}
// 	while (stack_b != NULL)
// 	{
// 		list_push(&stack_b, &stack_a, pb);
// 	}
// 	return ;
// }

void	reverse_sort_stack(t_sort **list, int status, int min)
{
	t_sort	*temp;
	t_sort	*last;

	temp = *list;
	last = lstlast_int(*list);
	if (lstsize_int(*list) < 4)
		rev_sort_three(&(*list), status);
	while (!list_is_sorted(*list, 2))
	{
		if (temp->next->content > temp->content && \
			temp->next->content > last->content)
		{
			list_swap(*list, status);
			list_rotate(&(*list), status);
		}
		else if (temp->next->content > temp->content && \
				temp->next->content < last->content)
		{
			list_swap(*list, status);
			list_rotate_reverse(&(*list), status);
		}
		else if (temp->next->content < temp->content)
		{
			list_rotate(&(*list), status);
		}
		temp = *list;
		last = lstlast_int(*list);
		printf("\n");
		printlist(*list);
	}
	return ;
}

void	sort_stack(t_sort **list, int status, int max)
{
	t_sort	*temp;

	temp = *list;
	if (lstsize_int(*list) <= 3)
		sort_three(&(*list), status);
	while (!list_is_sorted(*list, 1))
	{
		if (temp->content > temp->next->content && \
			temp->content < temp->next->next->content)
		{
			list_swap(*list, status);
		}
		else if (temp->content > temp->next->content && \
				temp->content > temp->next->next->content && \
				temp->content != max)
		{
			list_swap(*list, status);
			list_rotate(&(*list), status);
		}
		else
		{
			list_rotate_reverse(&(*list), status);
		}
		temp = *list;
	}
	return ;
}

void	least_worst_algo(t_swap *data)
{
	t_sort	*stack_a;
	t_sort	*stack_b;
	int		size;

	stack_a = array_to_list(data);
	stack_b = NULL;
	size = lstsize_int(stack_a);
	while (list_is_sorted(stack_a, 1) == 0)
	{
		while (lstsize_int(stack_a) > (size - data->median_index))
		{
			if (stack_a->content < data->median)
			{
				list_push(&stack_a, &stack_b, pb);
			}
			else if (stack_a->content)
			{
				list_rotate(&stack_a, ra);
			}
		}
		printf("STACK B >>>\n");
		printlist(stack_b);
		sort_stack(&stack_a, e_stack_a, data->max);
		reverse_sort_stack(&stack_b, e_stack_b, data->min);
		while (stack_b != NULL)
		{
			list_push(&stack_b, &stack_a, pa);
		}
	}
	lstdelete_int(stack_a);
	return ;
}
