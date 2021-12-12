/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilogy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:08:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/12 17:16:27 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	continue_sort_three(t_sort **list, int status);
void	sort_three(t_sort **list, int status);

void	simple_algo(t_swap *data, int status)
{
	t_sort	*stack_a;

	stack_a = array_to_list(data);
	sort_three(&stack_a, e_stack_a);
	return ;
}

void	sort_three(t_sort **list, int status)
{
	t_sort	*temp;

	temp = *list;
	if (temp->content > temp->next->content && \
		temp->next->next->content > temp->next->content && \
		temp->next->next->content > temp->content)
	{
		list_swap(*list, status);
	}
	else if (temp->content > temp->next->content && \
		temp->next->content > temp->next->next->content && \
		temp->next->next->content < temp->content)
	{
		list_swap(*list, status);
		list_rotate(&(*list), status);
	}
	else if (temp->content < temp->next->content && \
		temp->next->content > temp->next->next->content && \
		temp->next->next->content < temp->content)
		list_rotate_reverse(&(*list), status);
	else
		continue_sort_three(&list, status);
	return ;
}

void	continue_sort_three(t_sort **list, int status)
{
	t_sort	*temp;

	temp = *list;
	if (temp->content < temp->next->content && \
		temp->next->content > temp->next->next->content && \
		temp->next->next->content > temp->content)
	{
		list_swap(*list, status);
		list_rotate(&(*list), status);
	}
	else if (temp->content > temp->next->content && \
			temp->next->content > temp->next->next->content && \
			temp->next->next->content < temp->content)
	{
		list_swap(*list, status);
		list_rotate(&(*list), status);
	}
	else if (temp->content > temp->next->content && \
			temp->next->content < temp->next->next->content && \
			temp->next->next->content < temp->content)
		list_rotate(&(*list), status);
	return ;
}
