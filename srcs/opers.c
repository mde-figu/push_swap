/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:28:54 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/09 21:19:49 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_lst **dst, t_lst **src, t_vars vars, char *op)
{
	(vars.opers)[(vars.index)++] = ft_strdup(op);
	un_push(dst, src);
}

void	swap(t_lst **l, t_vars *vars, char *op)
{
	(vars->opers)[(vars->index)++] = ft_strdup(op);
	un_swap(l);
}

void	rotate(t_lst **l, t_vars *vars, char *op)
{
	(vars->opers)[(vars->index)++] = ft_strdup(op);
	un_rotate(l);
}

void	rev_rotate(t_lst **l, t_vars *vars, char *op)
{
	(vars->opers)[(vars->index)++] = ft_strdup(op);
	un_rev_rotate(l);
}
