/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:37:35 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/02 02:58:47 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_swap *data, int operation)
{
	if ((operation == pa) && (data->store.len_stack_b > 0))
	{
		move_stack_a(data);
		printf("pa\n");
	}
	if ((operation == pb) && (data->store.len_stack_a > 0))
	{
		move_stack_b(data);
		printf("pb\n");
	}
	else
		return ;
}
