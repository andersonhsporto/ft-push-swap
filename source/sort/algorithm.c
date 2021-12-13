/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:47:20 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/13 03:12:59 by anhigo-s         ###   ########.fr       */
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

void	reverse_sort_stack(t_sort **list, int status)
{
	t_sort	*temp;
	t_sort	*last;

	temp = *list;
	last = lstlast_int(*list);
	while (list_is_sorted(*list, 2) == 0)
	{
		if (temp->content < temp->next->content && \
			temp->next->content > last->content)
		{
			list_swap(*list, status);
			list_rotate(&(*list), status);
		}
		else if (temp->content < temp->next->content && \
			temp->next->content < last->content)
		{
			list_swap(*list, status);
		}
		else if (temp->content > temp->next->content)
			list_rotate_reverse(&(*list), status);
		temp = *list;
		last = lstlast_int(temp);
	}
	return ;
}

void	sort_stack(t_sort **list, int status)
{
	t_sort	*temp;

	temp = *list;
	while (list_is_sorted(*list, 1) == 0)
	{
		if (temp->content > temp->next->content && \
			temp->content < temp->next->next->content)
		{
			list_swap(*list, status);
		}
		else if (temp->content > temp->next->content && \
				temp->content > temp->next->next->content)
		{
			list_swap(*list, status);
			list_rotate(&(*list), status);
		}
		else if (temp->content < temp->next->content)
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
	size = lstsize_int(stack_a);
	while (list_is_sorted(stack_a, 1) == 0)
	{
		while (lstsize_int(stack_b) != size / 2)
		{
			if (stack_a->content < data->median)
			{
				list_push(&stack_a, &stack_b, pb);
			}
			list_rotate(&stack_a, ra);
		}
		sort_three(&stack_a, e_stack_a);
		printf("teste\n");
		while (stack_b != NULL)
		{
			sort_stack(&stack_b, e_stack_b);
			list_rotate(&stack_b, e_stack_b);
			list_push(&stack_b, &stack_a, pa);
		}
	}
	//printlist(stack_a);
	return ;
}
