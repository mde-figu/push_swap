/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_qsort_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:35:36 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/11 00:51:24 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		shift_b_part(t_vars *vars, _Bool label)
{
	int		i;
	int		j;

	i = 0;
	if (!(vars->parts_b)[0])
		++i;
	while ((vars->parts_b)[i])
		++i;
	if (!label)
	{
		while (i-- > 0)
			(vars->parts_b)[i + 1] = (vars->parts_b)[i];
		(vars->parts_b)[0] = 0;
	}
	else
	{
		n = 0;
		while (n < i)
		{
			(vars->parts_b)[n] = (vars->parts_b)[n + 1];
			++n;
		}
	}
}
/* Faz a ordenacao dos ultimos tres elementos, sem recursao*/
int			sort_three(t_lst **l_a, t_vars *vars)
{
	int		n;

	n = 0;
	while (n++ < 4)
		backtrack(l_a, n, vars, 0);
	if ((*l_a)->next &&\
			*(int*)((l_a)->value) > *(int*)((*l_a)->next->value))
		swap(l_a, vars, "sa\n");
	if (!eval_sort(*l_a, 0))
	{
		rotate(l_a, vars, "ra\n");
		if (*(int*)((*l_a)->value) > *(int*)((*l_a)->next->value))
			swap(l_a, vars, "sa\n");
		rev_rotate(l_a, vars, "rra\n");
		if (*(int*)((*l_a)->value) > *(int*)((*l_a)->next->value))
			swap(l_a, vars, "sa\n");
	}
}