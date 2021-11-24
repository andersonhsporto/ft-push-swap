/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:50:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/24 03:16:10 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

//REMOVER AO FINAL
# include <stdio.h>

# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

enum e_operations{
	sa,
	sb,
	ra,
	rb,
	rra,
	rrb
};

typedef struct s_arguments
{
	int		argc;
	char	**argv;
}	t_arguments;

typedef struct s_pile
{
	int		*stack_a;
}	t_pile;

typedef struct s_swap
{
	char		**arg_string;
	t_arguments	args;
	t_pile		store;
}	t_swap;

void	print_error(char *message, int exit_code);

void	inspect_arg(t_swap *data, int argc, char **argv);

void	free_array(void **array);
void	free_exit(t_swap *data);

int		ft_atoi_error(const char *str, t_swap *data);
#endif