/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:58:37 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/14 22:04:46 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	clean_elem(t_vars *vars, int c)
{
	free((vars->opers)[c]);
	free((vars->opers)[c + 1]);
	while ((vars->opers)[c] && (vars->opers)[c + 1])
	{
		(vars->opers)[c] = (vars->opers)[c + 2];
		(vars->opers)[c + 1] = (vars->opers)[c + 3];
		c += 2;
	}
}

static void rotate_or_push(t_vars *vars, int *c)
{
	while ((vars->opers)[*c] == (vars->opers)[*c + 1])
		++(*c);
	while ((vars->opers)[*c + 1] &&
			((!ft_strcmp((vars->opers)[*c], "pa\n") &&\
				!ft_strcmp((vars->opers)[*c + 1], "pb\n")) ||
			(!ft_strcmp((vars->opers)[*c], "pb\n") &&\
				!ft_strcmp((vars->opers)[*c + 1], "pa\n")) ||
			(!ft_strcmp((vars->opers)[*c], "ra\n") &&\
				!ft_strcmp((vars->opers)[*c + 1], "rra\n")) ||
			(!ft_strcmp((vars->opers)[*c], "rra\n") &&\
				!ft_strcmp((vars->opers)[*c + 1], "ra\n")) ||
			(!ft_strcmp((vars->opers)[*c], "rb\n") &&\
				!ft_strcmp((vars->opers)[*c], "rrb\n")) ||
			(!ft_strcmp((vars->opers)[*c], "rrb\n") &&\
				!ft_strcmp((vars->opers)[*c + 1], "rb\n"))))
		clean_elem(vars, (*c)--);
}

/*Erase_opers limpa operacoes redundantes, pex. um pa seguido de pb*/
void	erase_opers(t_vars *vars)
{
	int		c;

	c = 0;
	while ((vars->opers)[c] && (vars->opers)[c + 1])
	{
		if ((!ft_strcmp((vars->opers)[c], "sa\n") || !ft_strcmp((vars->opers)[c], "sb\n"))
			&& !ft_strcmp((vars->opers)[c], (vars->opers)[c + 1]))
			clean_elem(vars, c--);
		else if (!ft_strcmp((vars->opers)[c], "pa\n") || !ft_strcmp((vars->opers)[c], "pb\n")
				|| !ft_strcmp((vars->opers)[c], "ra\n") || !ft_strcmp((vars->opers)[c], "rra\n")
				|| !ft_strcmp((vars->opers)[c], "rb\n") || !ft_strcmp((vars->opers)[c], "rrb\n"))
			rotate_or_push(vars, &c);
		++c;
	}
}