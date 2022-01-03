/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:50:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/03 00:14:56 by anhigo-s         ###   ########.fr       */
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

enum e_stack_status{
	e_stack_a,
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
}	t_pile;

typedef struct s_swap
{
	char		**arg_string;
	t_arguments	args;
	t_pile		store;
	t_sort		*stk_a;
	int			*grp_max;
	int			max;
	int			min;
	int			size;
	int			number_group;
}	t_swap;

//check argo
void	inspect_arg(t_swap *data, int argc, char **argv);
void	inspect_sort(t_swap *data);
int		inspect_char(int c);

//error_utils
void	print_error(char *message, int exit_code);

//free_util
void	free_array(char **array);
void	free_exit(t_swap *data);

//ft_atoi_error
int		ft_atoi_error(const char *str, t_swap *data);

//check_string
void	inspect_string(t_swap *data, int argc, char **argv);

//push_operations
void	push(t_swap *data, int operation);

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

//list scan
t_sort	*array_to_list(t_swap *data);
void	scan_list(t_sort *info, t_swap *data);

//simple
void	simple_algo(t_swap *data);

//algo_medium
void	merge_sort(t_swap *data);

//init_utils
void	bubble_sort(int *tab, int size);
int		*array_dup(t_swap *data);
void	init_data(t_swap *data, int argc, char **argv);
void	scan_fourth(t_swap	*data);

//algo utils
int		find_min(t_sort *lst);
int		find_max(t_sort *lst);
int		find_index(t_sort *dst, int number);
int		lst_scan(t_sort *lst, int nb);
size_t	ft_sqrt(int number);

//remover
void	print_array(int *array, int size);

#endif