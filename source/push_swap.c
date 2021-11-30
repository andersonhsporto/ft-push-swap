/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:09:09 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/30 01:17:08 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_swap *data, int argc, char **argv)
{
	data->args.argc = argc;
	data->args.argv = argv;
	data->store.len_stack_b = 1;
	data->store.stack_b = (int *)malloc(1 * sizeof(int));
	return ;
}

int	main(int argc, char **argv)
{
	t_swap	data;

	if (argc > 1)
	{
		inspect_arg(&data, argc, argv);
		if (data.store.stack_a[0] > data.store.stack_a[1])
		{
			printf("%d\n", data.store.stack_a[0]);
			push_a(&data);
			free(data.store.stack_a);
			free(data.store.stack_b);
		}
	}
	return (0);
}
