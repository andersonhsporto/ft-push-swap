/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:21:34 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/12 17:08:59 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	inspect_duplicates(t_swap *data);
static void	inspect_int(t_swap *data);

void	inspect_arg(t_swap *data, int argc, char **argv)
{
	int	i;
	int	j;

	init_data(data, argc, argv);
	i = 1;
	while (data->args.argv[i] != 0)
	{
		j = 0;
		while (data->args.argv[i][j])
		{
			if (inspect_char(data->args.argv[i][j]))
			{
				print_error("Error", EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	inspect_duplicates(data);
	return ;
}

int	inspect_char(int c)
{
	if (ft_isdigit(c) || c == '-')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

static void	inspect_duplicates(t_swap *data)
{
	int	i;
	int	j;

	i = 1;
	while (data->args.argv[i] != 0)
	{
		j = i + 1;
		while (data->args.argv[j] != 0)
		{
			if (ft_strcmp((data->args.argv[i]), data->args.argv[j]) == 0)
			{
				print_error("Error", EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	inspect_int(data);
	return ;
}

static void	inspect_int(t_swap *data)
{
	int	i;

	data->store.stack_a = (int *)malloc((data->args.argc - 1) * sizeof(int));
	i = 0;
	while (i < (data->args.argc - 1))
	{
		data->store.stack_a[i] = ft_atoi_error(data->args.argv[i + 1], data);
		i++;
	}
	data->store.len_stack_a = (data->args.argc - 1);
	inspect_sort(data);
	return ;
}

void	inspect_sort(t_swap *data)
{
	int	index;

	index = 1;
	while (index < (data->store.len_stack_a))
	{
		if (data->store.stack_a[index - 1] > data->store.stack_a[index])
		{
			return ;
		}
		index++;
	}
	free(data->store.stack_a);
	exit(EXIT_SUCCESS);
	return ;
}
