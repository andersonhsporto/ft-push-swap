/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:09:09 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/25 00:15:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	data;

	if (argc > 1)
	{
		inspect_arg(&data, argc, argv);
		printf("%d\n", data.store.stack_a[0]);
		printf("%d\n", data.store.stack_a[1]);
		swap_a(&data);
		printf("%d\n", data.store.stack_a[0]);
		printf("%d\n", data.store.stack_a[1]);
		free(data.store.stack_a);
	}
	return (0);
}
