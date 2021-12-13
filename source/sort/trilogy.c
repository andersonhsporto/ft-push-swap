/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilogy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:08:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/13 14:35:27 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_continue_sort_three(t_sort **list, int status);
static void	continue_sort_three(t_sort **list, int status);
void		sort_three(t_sort **list, int status);
void		reverse_sort_three(t_sort **list, int status);

void	simple_algo(t_swap *data, int status)
{
	t_sort	*stack_a;

	stack_a = array_to_list(data);
	reverse_sort_three(&stack_a, e_stack_a);
	printlist(stack_a);
	return ;
}

void	sort_three(t_sort **list, int status)
{
	t_sort	*temp;

	temp = *list;
	if (list_is_sorted(temp, 1) == 1)
		return ;
	else if (lstsize_int(temp) == 2 && list_is_sorted(temp, 1) == 0 && \
		temp->content > temp->next->content)
		list_swap(*list, status);
	else if (temp->content > temp->next->content && \
		temp->next->next->content > temp->next->content && \
		temp->next->next->content > temp->content)
		list_swap(*list, status);
	else if (list_is_sorted(temp, 2) == 1)
	{
		list_swap(*list, status);
		list_rotate_reverse(&(*list), status);
	}
	else
		continue_sort_three(&(*list), status);
}

static void	continue_sort_three(t_sort **list, int status)
{
	t_sort	*temp;

	temp = *list;
	if (temp->content > temp->next->content && \
			temp->next->content < temp->next->next->content && \
			temp->next->next->content < temp->content)
		list_rotate(&(*list), status);
	else if (temp->content < temp->next->content && \
		temp->next->content > temp->next->next->content && \
		temp->next->next->content < temp->content)
	{
		list_rotate_reverse(&(*list), status);
	}
	else if (temp->content < temp->next->content && \
		temp->next->content > temp->next->next->content && \
		temp->next->next->content > temp->content)
	{
		list_swap(*list, status);
		list_rotate(&(*list), status);
	}
	return ;
}

void	reverse_sort_three(t_sort **list, int status)
{
	t_sort	*temp;

	temp = *list;
	if (list_is_sorted(temp, 2))
		return ;
	if (lstsize_int(temp) == 2 && list_is_sorted(temp, 1) == 1)
		list_swap(*list, status);
	else if (temp->content > temp->next->content && \
		temp->next->next->content > temp->next->content && \
		temp->next->next->content > temp->content)
		list_rotate_reverse(&(*list), status);
	else if ((list_is_sorted(temp, 1) == 1))
	{
		list_swap(*list, status);
		list_rotate_reverse(&(*list), status);
	}
	else
		reverse_continue_sort_three(&(*list), status);
}

static void	reverse_continue_sort_three(t_sort **list, int status)
{
	t_sort	*temp;

	temp = *list;
	if (temp->content > temp->next->content && \
			temp->next->content < temp->next->next->content && \
			temp->next->next->content < temp->content)
	{
		list_swap(*list, status);
		list_rotate(&(*list), status);
	}
	else if (temp->content < temp->next->content && \
		temp->next->content > temp->next->next->content && \
		temp->next->next->content < temp->content)
	{
		list_swap(*list, status);
	}
	else if (temp->content < temp->next->content && \
		temp->next->content > temp->next->next->content && \
		temp->next->next->content > temp->content)
	{
		list_rotate(&(*list), status);
	}
	printf("test\n");
	return ;
}
