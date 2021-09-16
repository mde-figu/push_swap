/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:17:54 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/16 14:20:09 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	**freeentry(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(str[j++]);
	free(str);
	return (0);
}

void	set_mem_free(t_lst *l_a, t_lst *l_b, t_vars *vars)
{
	int		c;
	t_lst	*tmp;

	c = 0;
	while ((vars->opers)[c])
		free((vars->opers)[c++]);
	free(vars->opers);
	free(vars->parts_a);
	free(vars->parts_b);
	free(vars);
	while (l_a)
	{
		tmp = l_a;
		l_a = l_a->next;
		free(tmp->value);
		free(tmp);
	}
	while (l_b)
	{
		tmp = l_b;
		l_b = l_b->next;
		free(tmp->value);
		free(tmp);
	}
}
