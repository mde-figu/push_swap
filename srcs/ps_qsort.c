/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:50:42 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/11 10:59:36 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ps_qsort(t_lst **l_a, t_lst **l_b, t_vars *vars)
{
	if (ran_sort(*l_a, (vars->parts_a)[0], 0))
	{
		while ((vars->parts_a)[0] > 3)
			re_push_a(l_a, l_b, vars);
		sort_three(l_a, vars);
	}
	(vars->parts_a)[0] = 0;
	if (ran_sort(*l_b, (vars->parts_b)[0], 1))
	{
		if ((vars->parts_b)[0] <= 3)
			push_rest_b(l_a, l_b, vars);
		else
			re_push_b(l_a, l_b, vars, 0);
	}
	else
	{
		while (((vars->parts_b)[0])--)
			push(l_a, l_b, vars, "pa\n");
		shift_b_part(vars, SHIFT_LEFT);
	}
	if ((vars->parts_b)[0])
		ps_qsort(l_a, l_b, vars);
	return (0);
}
