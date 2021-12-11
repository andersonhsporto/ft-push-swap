/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:37:35 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/09 15:04:57 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_swap *data, int operation)
{
	if ((operation == pa) && (data->store.len_stack_b > 0))
	{
		//printf("ANTES\n");
		//print_array(data->store.stack_a, data->store.len_stack_a);
		move_stack_a(data);
		printf("pa\n");
		//printf("DEPOIS\n");
		//print_array(data->store.stack_a, data->store.len_stack_a);
		//printf("DEPOIS\n");
		//print_array(data->store.stack_b, data->store.len_stack_b);
	}
	if ((operation == pb) && (data->store.len_stack_a > 0))
	{
		//printf("ANTES\n");
		//print_array(data->store.stack_a, data->store.len_stack_a);
		move_stack_b(data);
		printf("pb\n");
		//printf("DEPOIS\n");
		//print_array(data->store.stack_a, data->store.len_stack_a);
		//printf("DEPOIS\n");
		//print_array(data->store.stack_b, data->store.len_stack_b);
	}
	else
		return ;
}
