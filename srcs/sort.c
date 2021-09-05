/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:36:44 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/05 14:30:17 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_lst **l_a, t_lst **l_b, t_vars *vars)
{
	int		len;
	int		n;

	n = 1;
	len = lst_len(*l_a);
	if (len <= 6)
		while (!backtrack(l_a, n, &vars, 0))
		++n;
	else
	{
		(vars->parts_a)[0] = lst_len(*l_a);
		ps_qsort(l_a, l_b, vars); //implementar o qsort()  aqui
	}
	erase_opers(vars); // limpar o vars
}