/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:45:10 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/02 11:09:25 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vars	*set_vars(t_lst *l_a)
{
	t_vars	*new;
	size_t	size;

	size = lst_len(l_a) * 20;
	if (!(new = (t_vars*)ft_memalloc(sizeof(t_vars))))
		ft_error_memory();
	if (!(new->opers = (char**)ft_memalloc(size * sizeof(char*))))
		ft_error_memory();
	if (!(new->parts_a = (int*)ft_memalloc(sizeof(int))))
		ft_error_memory();
	if (!(new->parts_b = (int*)ft_memalloc(lst_len(l_a) * sizeof(int))))
		ft_error_memory();
	new->index = 0;
	new->need_rev = 0;
	new->piv = 0;
	return (new);
}
