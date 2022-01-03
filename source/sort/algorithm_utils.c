/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:47:20 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/02 23:40:16 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_sort *lst)
{
	int		min;
	t_sort	*tmp;

	tmp = lst;
	min = MAX_INT;
	while (tmp != NULL)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
		}
		tmp = tmp->next;
	}
	return (min);
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

int	lst_scan(t_sort *lst, int number)
{
	t_sort	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->content < number)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

size_t	ft_sqrt(int number)
{
	size_t	i;

	i = 0;
	while (i * i <= (size_t)number)
	{
		if (i * i == (size_t)number)
			return (i);
		i++;
	}
	return (i - 1);
}
