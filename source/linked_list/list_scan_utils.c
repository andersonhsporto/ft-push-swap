/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_scan_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:21:33 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/10 21:36:42 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_list(t_sort *info, t_swap *data)
{
	t_sort	*temp;

	if (info == NULL)
		return ;
	temp = info;
	data->max = temp->content;
	data->min = temp->content;
	while (temp->next != NULL)
	{
		if (temp->content > data->max)
			data->max = temp->content;
		if (temp->content < data->min)
			data->min = temp->content;
		temp = temp->next;
	}
	//printf("max = %d, min = %d\n", data->max, data->min);
	return ;
}
