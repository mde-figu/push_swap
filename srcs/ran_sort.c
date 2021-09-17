/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ran_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:29:36 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/17 15:28:35 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ran_sort(t_lst *ls, int len, _Bool label)
{
	int		c;

	c = 0;
	if (ls)
	{
		while (ls->next && --len)
		{
			if (!label && (*(int *)(ls->value) > *(int *)(ls->next->value)))
				++c;
			else if (label && (*(int *)(ls->value) < *(int *)(ls->next->value)))
				++c;
			ls = ls->next;
		}
	}
	return (c);
}
