/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:00:19 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/02 17:50:59 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_array(char **args);
static void	inspect_duplicates(t_swap *data);
static void	inspect_int(t_swap *data);

void	inspect_string(t_swap *data, int argc, char **argv)
{
	int	i;
	int	j;

	init_data(data, argc, argv);
	data->args.argv = ft_split(argv[1], ' ');
	//print_c_array(data->args.argv, 3);
	data->args.argc = count_array(data->args.argv);
	i = 0;
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

static int	count_array(char **args)
{
	int	i;

	i = 1;
	while (args[i] != 0)
	{
		i++;
	}
	return (i);
}

static void	inspect_duplicates(t_swap *data)
{
	int	i;
	int	j;

	i = 0;
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

	data->store.stack_a = (int *)malloc((data->args.argc) * sizeof(int));
	i = 0;
	while (i < (data->args.argc))
	{
		data->store.stack_a[i] = ft_atoi_error(data->args.argv[i], data);
		i++;
	}
	data->store.len_stack_a = (data->args.argc);
	//printf(">>%d \n", data->store.len_stack_a);
	free_array(data->args.argv);
	//print_array(data->store.stack_a, data->store.len_stack_a);
	inspect_sort(data);
	return ;
}
