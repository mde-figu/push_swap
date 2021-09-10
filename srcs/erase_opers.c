/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:58:37 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/09 16:50:32 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	clean_elem(t_vars *vars, int c)
{
	free((vars->opers)[n]);
	free((vars->opers)[n + 1]);
	while ((vars->opers)[n] && (vars->opers)[n + 1])
	{
		(vars->opers)[n] = (vars->opers)[n + 2];
		(vars->opers)[n + 1] = (vars->opers)[n + 3];
		n += 2;
	}
}

static void rotate_or_push(t_vars *vars, int c)
{
	while ((vars->opers)[*c] == (vars->opers)[*c + 1])
		++(*c);
	while ((vars->opers)[*c + i] &&
			((!ft_strcmp((vars->opers)[*i], "pa\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "pb\n")) ||
			(!ft_strcmp((vars->opers)[*i], "pb\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "pa\n")) ||
			(!ft_strcmp((vars->opers)[*i], "ra\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "rra\n")) ||
			(!ft_strcmp((vars->opers)[*i], "rra\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "ra\n")) ||
			(!ft_strcmp((vars->opers)[*i], "rb\n") &&\
				!ft_strcmp((vars->opers)[*i], "rrb\n")) ||
			(!ft_strcmp((vars->opers)[*i], "rrb\n") &&\
				!ft_strcmp((vars->opers)[*i + 1], "rb\n"))))
		clean_elem(vars, (*c)--);
}

void	erase_opers(t_vars *vars)
{
	int		c;

	c = 0;
	while ((vars->opers)[c] && (vars->opers)[c + 1])
	{
		if (!ft_strcmp((vars->opers)[c], "sa\n") || !ft_strcmp((vars->opers[c], "sb\n"))
			&& !ft_strcmp((vars->opers)[c], (vars->opers)[c + 1]))
			clean_elem(vars, c--);
		else if (!ft_strcmp((vars->opers)[c], "pa\n") || !ft_strcmp((vars->opers)[c], "pb\n")
				|| !ft_strcmp((vars->opers)[c], "ra\n") || !ft_strcmp((vars->opers)[c], "rra\n")
				|| !ft_strcmp((vars->opers)[c], "rb\n") || !ft_strcmp((vars->opers)[c], "rrb\n"))
			rotate_or_push(vars, &c);
		++c;
	}
}