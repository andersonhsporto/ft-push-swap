/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:37:45 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/08 20:51:10 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_status(t_swap *data)
{
	if (data->args.argc <= 4)
	{
		third_number(data);
		return ;
	}
	if (data->args.argc > 4)
		worst_algo(data);
	return ;
}
