/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_opers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:44:36 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/07 15:54:15 by mde-figu         ###   ########.fr       */
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

	vars->piv = get_middle(*l_a, (vars->parts_a)[0]);
	shift_b_part(vars, SHIFT_RIGHT);
}