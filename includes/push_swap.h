/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:50:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/02 03:34:47 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//REMOVER AO FINAL
# include <stdio.h>
# include <math.h>

# include "lists.h"

# include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT 2147483648
# define INT_MIN -2147483648

enum e_swap{
	sa,
	sb,
	ss
};

enum e_push{
	pa,
	pb
};

enum e_rotate{
	ra,
	rb,
	rr
};

enum e_rrotate{
	rra,
	rrb,
	rrr
};

enum e_status{
	status_1,
	status_2,
	status_3,
	status_4,
	status_5
};

enum e_stack_status{
	e_stack_a,
	e_stack_b
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

typedef struct s_index
{
	int	*grp_min;
	int	*grp_max;
}	t_index;

typedef struct s_swap
{
	char		**arg_string;
	t_arguments	args;
	t_pile		store;
	t_utils		value;
	t_index		merge;
	t_sort		*stk_a;
	int			max;
	int			min;
	int			size;
	int			number_group;
	int			median;
	int			median_index;
}	t_swap;

void	inspect_arg(t_swap *data, int argc, char **argv);
int		inspect_char(int c);

void	print_error(char *message, int exit_code);

void	free_array(char **array);
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

//list scan
t_sort	*array_to_list(t_swap *data);
void	scan_list(t_sort *info, t_swap *data);

//trilogy
void	sort_cont(t_sort **list, int status);
void	sort_three(t_sort **list, int status);
void	rev_sort_three(t_sort **list, int status);
void	rev_sort_cont(t_sort **list, int status);
void	simple_algo(t_swap *data);

void	inspect_sort(t_swap *data);

void	least_worst_algo(t_swap *data);
t_sort	*array_to_list(t_swap *data);
void	sort_stack(t_sort **list, int status, int max);
#endif