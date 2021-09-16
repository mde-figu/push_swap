/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_qsort_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:56:13 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/15 16:28:35 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_in_order(t_lst **ls, int piv, _Bool label)
{
	int		c;

	c = 0;
	while (*ls)
	{
		if (!label && *(int*)((*ls)->value) > piv)
			++c;
		else if (label && *(int*)((*ls)->value) <= piv)
			++c;
		else
			break ;
		*ls = (*ls)->next;
	}
	return (c);
}

_Bool		eval_rrr(t_lst *ls, int piv, _Bool label)
{
	int		no_good;
	int		good;

	while (ls)
	{
		no_good = count_in_order(&ls, piv, label);
		good = count_in_order(&ls, piv, label);
	}
	if (no_good > good)
		return (1);
	else
		return (0);
}

void		ops_print(char **operations)
{
	while (*operations)
		ft_putstr(*(operations)++);
}
