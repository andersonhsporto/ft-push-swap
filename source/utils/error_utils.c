/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:01:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/09 14:02:09 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *message, int exit_code)
{
	ft_putstr_fd(message, 2);
	exit(exit_code);
}

//remover
void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("NUMERO:%d, POSIÇÂO I:%d\n", array[i], i);
		i++;
	}
	return ;
}
