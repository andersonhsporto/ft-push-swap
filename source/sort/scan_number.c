/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:37:45 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/02 18:17:13 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_status(t_swap *data)
{
	if (data->store.len_stack_a <= 5)
	{
		simple_algo(data);
		return ;
	}
	else if (data->store.len_stack_a > 5)
	{
		quick_test(data);
		return ;
	}
}
