/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilogy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:08:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/10 20:17:19 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	continue_third_number(t_swap *data);

void	third_number(t_swap *data)
{
	if (data->args.argc == 3)
	{
		ft_putendl_fd("sa", 1);
		return ;
	}
	if (data->store.stack_a[0] > data->store.stack_a[1] && \
		data->store.stack_a[2] > data->store.stack_a[1] && \
		data->store.stack_a[2] > data->store.stack_a[0])
	{
		ft_putendl_fd("sa", 1);
	}
	if (data->store.stack_a[0] > data->store.stack_a[1] && \
		data->store.stack_a[1] > data->store.stack_a[2] && \
		data->store.stack_a[2] < data->store.stack_a[0])
	{
		ft_putendl_fd("sa", 1);
		ft_putendl_fd("rra", 1);
	}
	continue_third_number(data);
}

void	continue_third_number(t_swap *data)
{
	if (data->store.stack_a[0] < data->store.stack_a[1] && \
		data->store.stack_a[1] > data->store.stack_a[2] && \
		data->store.stack_a[2] < data->store.stack_a[0])
	{
		ft_putendl_fd("rra", 1);
	}
	if (data->store.stack_a[0] < data->store.stack_a[1] && \
		data->store.stack_a[1] > data->store.stack_a[2] && \
		data->store.stack_a[2] > data->store.stack_a[0])
	{
		ft_putendl_fd("sa", 1);
		ft_putendl_fd("ra", 1);
	}
	if (data->store.stack_a[0] > data->store.stack_a[1] && \
		data->store.stack_a[1] < data->store.stack_a[2] && \
		data->store.stack_a[2] < data->store.stack_a[0])
	{
		ft_putendl_fd("ra", 1);
	}
	return ;
}
