/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:01:16 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/03 00:16:43 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *message, int exit_code)
{
	ft_putendl_fd(message, 2);
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

//remover
void	print_c_array(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("STRING:%s, POSIÇÂO I:%d\n", array[i], i);
		i++;
	}
	return ;
}

//remover
void	printlist(t_sort *info)
{
	t_sort	*temp;

	temp = info;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			printf("%d \n", temp->content);
		else
			printf("%d \n", temp->content);
		temp = temp->next;
	}
	return ;
}
