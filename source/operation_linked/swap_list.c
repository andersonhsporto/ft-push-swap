/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:31:14 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/12 17:47:38 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_swap(t_sort *src, int status)
{
	int	head;
	int	temp;

	if (lstsize_int(src) > 1)
	{
		head = src->content;
		temp = src->next->content;
		src->content = temp;
		src->next->content = head;
		if (status == sa)
			ft_putendl_fd("sa", 1);
		if (status == sb)
			ft_putendl_fd("sb", 1);
	}
	return ;
}
