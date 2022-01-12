/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:50:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/01/12 16:35:02 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	rrr,
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
	t_arguments	args;
	t_pile		store;
	t_sort		*stk_a;
	int			*grp_max;
	int			max;
}	t_swap;

void	inspect_arg(t_swap *data, int argc, char **argv);
void	inspect_sort(t_swap *data);
int		inspect_char(int c);

void	print_error(char *message, int exit_code);

void	free_array(char **array);
void	free_exit(t_swap *data);

int		ft_atoi_error(const char *str, t_swap *data);
int		ft_isspace(int c);

void	inspect_string(t_swap *data, char **argv);

void	scan_status(t_swap *data);

t_sort	*array_to_list(t_swap *data);
int		find_min(t_sort *lst);
int		find_max(t_sort *lst);
int		lst_scan(t_sort *lst, int nb);
int		find_index(t_sort *dst, int number);

void	simple_algo(t_swap *data);

void	merge_sort(t_swap *data);
size_t	ft_sqrt(int number);

void	bubble_sort(int *tab, int size);
int		*array_dup(t_swap *data);
void	init_data(t_swap *data, int argc, char **argv);
void	scan_groups(t_swap	*data);
#endif