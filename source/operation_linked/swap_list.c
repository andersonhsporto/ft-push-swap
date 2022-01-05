/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:31:14 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/04 23:17:57 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_swap(t_sort *info, int status)
{
	int	head;
	int	temp;

	if (lstsize_int(info) > 1)
	{
		head = info->content;
		temp = info->next->content;
		info->content = temp;
		info->next->content = head;
		if (status == sa)
			ft_putendl_fd("sa", 1);
		if (status == sb)
			ft_putendl_fd("sb", 1);
	}
	return ;
}
