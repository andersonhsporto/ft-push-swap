/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:47:20 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/02 18:30:58 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			//printf("teste\n");
			list_rotate_reverse(&(*list), status);
		}
		temp = *list;
	}
	return ;
}

int	find_max(t_sort *lst)
{
	int		max;
	t_sort	*tmp;

	tmp = lst;
	max = INT_MIN;
	while (tmp != NULL)
	{
		if (max < tmp->content)
		{
			max = tmp->content;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	find_index(t_sort *dst, int number)
{
	t_sort	*tmp;
	int		index;

	tmp = dst;
	index = 0;
	while (tmp != NULL)
	{
		if (number == tmp->content)
		{
			break ;
		}
		tmp = tmp->next;
		index++;
	}
	return (index);
}
