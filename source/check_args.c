/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:21:34 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/30 02:13:12 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		inspect_char(int c);
void	inspect_duplicates(t_swap *data);
void	inspect_int(t_swap *data);
void	inspect_sort(t_swap *data);

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
				print_error("Error\n", EXIT_FAILURE);
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

void	inspect_duplicates(t_swap *data)
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
				print_error("Error\n", EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	inspect_int(data);
	return ;
}

void	inspect_int(t_swap *data)
{
	int	i;

	data->store.stack_a = (int *)malloc((data->args.argc - 2) * sizeof(int));
	i = 0;
	while (i < (data->args.argc - 2))
	{
		data->store.stack_a[i] = ft_atoi_error(data->args.argv[i + 1], data);
		i++;
	}
	data->store.len_stack_a = i;
	inspect_sort(data);
	return ;
}

void	inspect_sort(t_swap *data)
{
	int	i;

	i = 0;
	while (i < data->store.len_stack_a)
	{
		if ((i < (data->store.len_stack_a - 1)) && data->store.stack_a[i]
			> data->store.stack_a[i + 1])
		{
			return ;
		}
		i++;
	}
	free(data->store.stack_a);
	free(data->store.stack_b);
	exit(EXIT_SUCCESS);
	return ;
}
