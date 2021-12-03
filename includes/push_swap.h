/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:50:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/02 20:40:22 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//REMOVER AO FINAL
# include <stdio.h>

# include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT 2147483648

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
	int		len_stack_a;
	int		len_stack_b;
	int		*stack_b;
}	t_pile;

typedef struct s_swap
{
	char		**arg_string;
	t_arguments	args;
	t_pile		store;
}	t_swap;

void	print_error(char *message, int exit_code);

void	inspect_arg(t_swap *data, int argc, char **argv);
int		inspect_char(int c);

void	free_array(void **array);
void	free_exit(t_swap *data);

int		ft_atoi_error(const char *str, t_swap *data);

void	init_data(t_swap *data, int argc, char **argv);

//operations
void	push_a(t_swap *data);
void	push_b(t_swap *data);

//utils
int		*copy_int_vector(int *vector, int size);
void	add_integer(int integer, int **vector, int size);
void	delete_integer(int **vector, int size);

//rotate
void	rotate_a(t_swap *data);
void	rotate_b(t_swap *data);
#endif