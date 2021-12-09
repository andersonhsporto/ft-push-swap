/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:09:09 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/09 14:43:51 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	data;

	if (argc == 2)
	{
		inspect_string(&data, argc, argv);
	}
	if (argc > 2)
	{
		inspect_arg(&data, argc, argv);
		//printf("a%d \n", data.store.stack_a[0]);
		//worst_algo(&data);
		push(&data, pb);
		//printf("b%d \n", data.store.stack_b[0]);
		//printf("a%d \n", data.store.stack_a[0]);
		//push_a(&data);
		//printf("a%d \n", data.store.stack_a[0]);
		//scan_status(&data);
	}
	free(data.store.stack_a);
	free(data.store.stack_b);
	return (0);
}
