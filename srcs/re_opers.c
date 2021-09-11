/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_opers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:44:36 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/10 23:35:32 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	re_push_a(t_lst **l_a, t_lst **l_b, t_vars *vars)
{
	int		q;
	int		half;
	int		go_rra;

	q = 0;
	if ((vars->parts_a)[0] % 2)
		half = (vars->parts_a)[0] / 2 + 1;
	else
		half = (vars->parts_a)[0] / 2;

	vars->piv = middle_of_three(*l_a, (vars->parts_a)[0]);
	shift_b_part(vars, SHIFT_RIGHT);
	if (!(vars->parts_b)[1])
		vars->need_rev = is_reversed(*l_a);
	else
		vars->need_rev = 0;
	go_rra = is_useful_rrr(*l_a, vars->piv, 0);
	while (half)
	{
		if (go_rra && *(int*)((lstn(*l_a, \
							lst_len(*l_a)))->value) <= vars->piv)
			rev_rotate(l_a, vars, "rra\n");
		if (*(int*)((*l_a)->value) <= vars->piv &&\
				((vars->parts_a)[0])-- && ++((vars->parts_b)[0]) && half--)
			get_cost(l_a, l_b, vars);
		else if (++q)
			rotate(l_a, vars, "ra\n");
	}
	if ((vars->parts_a)[0] != (int)lst_len(*l_a))
		while (q--)
			rev_rotate(l_a, vars, "rra\n");
}

static void		repush_b_return(t_lst **l_a, t_lst **l_b, t_vars *vars, int q)
{
	if ((vars->parts_b)[1])
		while (q--)
		{
			rev_rotate(l_b, vars, "rrb\n");
			if (!is_between(*l_a, *l_b, \
				*(int*)((*l_b)->value), *(int*)((*l_a)->value)) &&\
					((vars->parts_b)[0])-- && ((vars->parts_a)[0])++)
				push(l_a, l_b, vars, "pa\n");
		}
	if ((vars->parts_b)[0] <= 0)
		shift_b_part(vars, SHIFT_LEFT);
}

void	re_push_b(t_lst **l_a, t_lst **l_b, t_vars *vars, int c)
{
	int		i;
	int		go_rrb;
	int		half;

	i = (vars->parts_b)[0];
	half = (vars->parts_b)[0] / 2;
	vars->piv = middle_of_three(l_b, (vars->parts_b)[0]);
	go_rrb = is_useful_rrr(*l_b, vars->piv, 1);
	while (i-- > 0 && half)
	{
		if (go_rrb && *(int*)((lstn(*l_b, \
						lst_len(*l_b)))->value) > vars->piv)
			rev_rotate(l_b, vars, "rrb\n");
		if (!ran_sort(*l_b, (vars->parts_b)[0], 0))
			while (i-- && ++q)
				get_rotate(l_b, vars, "rb\n");
		if ((*(int*)((*l_b)->value) > vars->piv) &&\
				((vars->parts_b)[0])-- && ++((vars->parts_a)[0]) && half--)
			push(l_a, l_b, vars, "pa\n");
		else if (++q)
			rotate(l_b, vars, "rb\n");
		need_to_swap(l_a, l_b, vars);
	}
	repush_b_return(l_a, l_b, vars, q);
}
