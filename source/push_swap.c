/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:09:09 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/02 21:05:52 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	data;

	if (argc == 2)
	{
		inspect_string(&data, argc, argv);
		printf(">>[0] %d\n", data.store.stack_a[0]);
	}
	if (argc > 2)
	{
		inspect_arg(&data, argc, argv);
		if (data.store.stack_a[0] > data.store.stack_a[1])
		{
			printf("%d\n", data.store.stack_a[0]);
			//rotate_a(&data);
			reverse_rotate_a(&data);
			printf("%d\n", data.store.stack_a[0]);
			free(data.store.stack_a);
			free(data.store.stack_b);
		}
	}
	return (0);
}
