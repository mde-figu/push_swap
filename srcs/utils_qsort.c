/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_qsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 23:46:33 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/17 14:58:16 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* is between verifica se ha um pivot no meio do conjunto*/
_Bool	is_between(t_lst *l_a, t_lst *l_b, int one, int two)
{
	int		c;

	c = 0;
	while (l_a || l_b)
	{
		if (l_a && *(int *)(l_a->value) < two && \
				*(int *)(l_a->value) > one)
			++c;
		if (l_b && *(int *)(l_b->value) < two && \
				*(int *)(l_b->value) > one)
			++c;
		if (l_a)
			l_a = l_a->next;
		if (l_b)
			l_b = l_b->next;
	}
	return (c);
}
/* need to swap, verifica valor se atual maior que o proximo e se nao existe 
um pivot no meio, caso positivo faz o Swap da stack a*/

void	need_to_swap(t_lst **l_a, t_lst **l_b, t_vars *vars)
{
	if (*(int *)((*l_a)->value) > *(int *)((*l_a)->next->value) && \
			!is_between(*l_a, *l_b, \
			*(int *)((*l_a)->next->value), *(int *)((*l_a)->value)))
		swap(l_a, vars, "sa\n");
}

void	get_back(t_lst **l_a, t_lst **l_b, t_vars *vars)
{
	push(l_b, l_a, vars, "pb\n");
	if (vars->need_rev && *l_b)
		rotate(l_b, vars, "rb\n");
}

void	push_rest_b(t_lst **l_a, t_lst **l_b, t_vars *vars)
{
	while (((vars->parts_b)[0])-- && ++((vars->parts_a)[0]))
	{
		if ((vars->parts_b)[0] >= 1 && *(int *)((*l_b)->value) < \
				*(int *)((*l_b)->next->value))
			swap(l_b, vars, "sb\n");
		if ((*l_a)->next && *(int *)((*l_a)->value) > \
				*(int *)((*l_a)->next->value))
			swap(l_a, vars, "sa\n");
		push(l_a, l_b, vars, "pa\n");
	}
	sort_three(l_a, vars);
	shift_b_part(vars, SHIFT_LEFT);
}
