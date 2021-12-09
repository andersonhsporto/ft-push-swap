/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:50:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/09 14:44:49 by anhigo-s         ###   ########.fr       */
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
	pa,
	pb,
	sb,
	ra,
	rb,
	rra,
	rrb
};

enum e_status{
	status_1,
	status_2,
	status_3,
	status_4,
	status_5
};

enum e_stack{
	stack_0,
	a_stack,
	b_stack,
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
	int		*stack_b;
	int		len_stack_b;
	int		*temp_number;
}	t_pile;

typedef struct s_utils
{
	int		max;
	int		min;
}	t_utils;

typedef struct s_swap
{
	char		**arg_string;
	t_arguments	args;
	t_pile		store;
	t_utils		value;
}	t_swap;

void	print_error(char *message, int exit_code);

void	inspect_arg(t_swap *data, int argc, char **argv);
int		inspect_char(int c);

void	free_array(void **array);
void	free_exit(t_swap *data);

int		ft_atoi_error(const char *str, t_swap *data);

void	init_data(t_swap *data, int argc, char **argv);

//operations
void	push(t_swap *data, int operation);

//check_string
void	inspect_string(t_swap *data, int argc, char **argv);

//utils
void	move_stack_a(t_swap *data);
void	move_stack_b(t_swap *data);

//rotate
void	rotate_a(t_swap *data, int status);
void	rotate_b(t_swap *data, int status);

//swap
void	swap_a(t_swap *data);
void	swap_b(t_swap *data);
void	swap_ss(t_swap *data);

//reverse_rotate
void	reverse_rotate_a(t_swap *data, int status);
void	reverse_rotate_b(t_swap *data, int status);
void	reverse_rotate_r(t_swap *data);

//scan
void	scan_status(t_swap *data);

void	third_number(t_swap *data);
//remover
void	print_array(int *array, int size);
#endif