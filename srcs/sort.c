/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:36:44 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/17 12:07:07 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

_Bool	eval_sort(t_lst *l_a, t_lst *l_b)
{
	int		previous;

	if (l_b || !l_a)
		return (FALSE);
	previous = *(int*)(l_a->value);
	l_a = l_a->next;
	while (l_a)
	{
		if (*(int*)(l_a->value) < previous)
			return (FALSE);
		previous = *(int*)(l_a->value);
		l_a = l_a->next;
	}
	return (TRUE);
}

void	sort(t_lst **l_a, t_lst **l_b, t_vars *vars)
{
	int		len;
	int		i;

	i = 1;
	len = lst_len(*l_a);
	if (len <= 6)
		while (!backtrack(l_a, i, vars, 0))
			++i;
	else
	{
		(vars->parts_a)[0] = lst_len(*l_a);
		ps_qsort(l_a, l_b, vars);
	}
	erase_opers(vars);
}
