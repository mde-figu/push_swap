/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:45:10 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/17 15:59:08 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_vars	*set_vars(t_lst *l_a)
{
	t_vars	*new;
	size_t	size;

	size = lst_len(l_a) * 20;
	new = (t_vars *)ft_memalloc(sizeof(t_vars));
	if (!new)
		ft_error_memory();
	new->opers = (char **)ft_memalloc(size * sizeof(char *));
	if (!new->opers)
		ft_error_memory();
	new->parts_a = (int *)ft_memalloc(sizeof(int));
	if (!new->parts_a)
		ft_error_memory();
	new->parts_b = (int *)ft_memalloc(lst_len(l_a) * sizeof(int));
	if (!new->parts_b)
		ft_error_memory();
	new->index = 0;
	new->need_rev = 0;
	new->piv = 0;
	return (new);
}
