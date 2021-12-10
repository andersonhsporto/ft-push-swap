/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:07:28 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/12/10 13:12:44 by anhigo-s         ###   ########.fr       */
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
void	lstdelone_int(t_sort *lst, void (*del)(void*));
void	lstclear_int(t_sort **lst, void (*del)(void *));

void	printlist(t_sort *info);
#endif