/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:03:00 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/05 13:26:34 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	rollback(t_vars *vars)
{
	--(vars->index);
	free((vars->opers)[vars->index]);
	(vars->opers)[vars->index] = 0;
	return (1);
}

static void	eval_stack(char **sw, char **rot, char **rrot, _Bool label)
{
	if (label)
	{
		*sw = "sb\n";
		*rot = "rb\n";
		*rrot = "rrb\n";
	}
	else
	{
		*sw = "sa\n";
		*rot = "rb\n";
		*rrot = "rrb\n";
	}
}
int	backtrack(t_lst **l, int n, t_vars vars, _Bool label)
{
	char	*sw;
	char	*rot;
	char	*rrot;

	eval_stack(&sw, &rot, &rrot, label);
	if (eval_sort(*l, 0) || !(*l))
		return (1);
	if (n <= 0)
		return (0);
	swap(l, vars, sw);
	if (!backtrack(l, n - 1, vars, label) && rollback(vars))
		un_swap(l);
	else
		return (1);
	rotate(l, vars, rot);
	if (!backtrack(l, n - 1, vars, label) && rollback(vars))
		un_rev_rotate(l); // nao esta claro se un_rotate ou un_rev_rotate

	else
		return (1);
	rev_rotate(l, vars, rrot);
	if (!backtrack(l, n - 1, vars, label) && rollback(vars))
		un_rotate(l);
	else
		return (1);
	return (0);
}
