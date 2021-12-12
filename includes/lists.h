/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:07:28 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/11 14:47:43 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

typedef struct s_sort
{
	int				content;
	struct s_sort	*next;
}	t_sort;

t_sort	*lstnew_int(int content);
void	lstadd_front_int(t_sort **lst, t_sort *new);
int		lstsize_int(t_sort *lst);
t_sort	*lstlast_int(t_sort *lst);
void	lstadd_back_int(t_sort **lst, t_sort *new);
void	lstdelete_int(t_sort **lst);

void	list_push(t_sort **src, t_sort **dst, int status);
void	list_rotate_reverse(t_sort **info, int status);
void	list_rotate_reverse_rrr(t_sort **stack_a, t_sort **stack_b);
void	list_rotate(t_sort **info, int status);
void	list_rotate_rr(t_sort **stack_a, t_sort **stack_b);
void	list_swap(t_sort *info, int status);
void	list_swap_ss(t_sort *stack_a, t_sort *stack_b);

t_sort	*lst_dup_int(t_sort *info);

void	printlist(t_sort *info);
#endif