/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:37:45 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/11 23:12:41 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_status(t_swap *data)
{
	if (data->args.argc <= 4)
	{
		third_number(data);
		free(data->store.stack_a);
		free(data->store.stack_b);
		return ;
	}
	if (data->args.argc > 4)
	{
		least_worst_algo(data);
	}
	return ;
}
