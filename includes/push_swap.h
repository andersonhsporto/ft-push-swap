/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:50:53 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/11/23 02:38:53 by anhigo-s         ###   ########.fr       */
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

typedef struct s_swap
{
	char	**arg_string;
	int		**number_list;
}	t_swap;

void	print_error(char *message, int exit_code);

#endif