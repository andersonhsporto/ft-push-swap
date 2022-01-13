/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:00:19 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/12 16:57:23 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	inspect_spaces(char **argv);
static int	count_array(char **args);
static void	inspect_duplicates(t_swap *data);
static void	inspect_int(t_swap *data);

void	inspect_string(t_swap *data, char **argv)
{
	int	i;
	int	j;

	inspect_spaces(argv);
	data->args.argv = ft_split(argv[1], ' ');
	data->args.argc = count_array(data->args.argv);
	i = 0;
	while (data->args.argv[i] != 0)
	{
		j = 0;
		while (data->args.argv[i][j])
		{
			if (inspect_char(data->args.argv[i][j]))
			{
				free_array(data->args.argv);
				print_error("Error", EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	inspect_duplicates(data);
	return ;
}

static void	inspect_spaces(char **argv)
{
	int	index;
	int	temp;

	index = 0;
	temp = 0;
	while (argv[1][index] != '\0')
	{
		if (ft_isspace(argv[1][index]) == 0)
		{
			temp++;
		}
		index++;
	}
	if (temp == 0)
	{
		exit(EXIT_SUCCESS);
	}
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
				free_array(data->args.argv);
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
	free_array(data->args.argv);
	inspect_sort(data);
	return ;
}
