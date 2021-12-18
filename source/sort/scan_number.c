/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:37:45 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/17 22:05:15 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_status(t_swap *data)
{
	if (data->args.argc <= 4)
	{
		simple_algo(data);
		return ;
	}
	else if (data->args.argc > 4)
	{
		quick_test(data);
		return ;
	}
}
