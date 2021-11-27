/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:09:09 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/27 03:39:47 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	data;

	if (argc > 1)
	{
		inspect_arg(&data, argc, argv);
		printf("Size args %d\n", data.store.len_stack_a);
		printf("args[0] %d\n", data.store.stack_a[0]);
		if (data.store.stack_a[0] > data.store.stack_a[1])
		{
			delete_integer(data.store.stack_a, &data.store.len_stack_a);
			printf("Size args %d\n", data.store.len_stack_a);
		}
		printf("args[0] %d\n", data.store.stack_a[0]);
		free(data.store.stack_a);
		free(data.store.stack_b);
	}
	return (0);
}
