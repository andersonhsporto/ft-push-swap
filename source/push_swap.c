/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:09:09 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/10 18:44:14 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	data;
	t_sort	*info;

	if (argc == 2)
	{
		inspect_string(&data, argc, argv);
	}
	if (argc > 2)
	{
		inspect_arg(&data, argc, argv);
		info = array_to_list(&data);
		printlist(info);
		printf("###################\n");
		list_rotate_reverse(&info, ra);
		printlist(info);
		printf("###################\n");
	}
	return (0);
}
