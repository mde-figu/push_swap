/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_qsort_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:35:36 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/14 16:40:42 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		shift_b_part(t_vars *vars, _Bool label)
{
	int		i;
	int		j;

	i = 0;
	if (!(vars->parts_b)[0])
		++i;
	while ((vars->parts_b)[i])
		++i;
	if (!label)
	{
		while (i-- > 0)
			(vars->parts_b)[i + 1] = (vars->parts_b)[i];
		(vars->parts_b)[0] = 0;
	}
	else
	{
		j = 0;
		while (j < i)
		{
			(vars->parts_b)[j] = (vars->parts_b)[j + 1];
			++j;
		}
	}
}
/* Faz a ordenacao dos ultimos tres elementos, sem recursao*/
void			sort_three(t_lst **l_a, t_vars *vars)
{
	int		n;

	n = 0;
	while (n++ < 4)
		backtrack(l_a, n, vars, 0);
	if ((*l_a)->next &&\
			*(int*)((*l_a)->value) > *(int*)((*l_a)->next->value))
		swap(l_a, vars, "sa\n");
	if (!eval_sort(*l_a, 0))
	{
		rotate(l_a, vars, "ra\n");
		if (*(int*)((*l_a)->value) > *(int*)((*l_a)->next->value))
			swap(l_a, vars, "sa\n");
		rev_rotate(l_a, vars, "rra\n");
		if (*(int*)((*l_a)->value) > *(int*)((*l_a)->next->value))
			swap(l_a, vars, "sa\n");
	}
}

static int	compare(t_lst *ls, int len, int nbr, _Bool label)
{
	int	greater;
	int	less;

	less = 0;
	greater = 0;
	while (ls && len--)
	{
		if (*(int*)(ls->value) > nbr)
			++greater;
		else if (*(int*)(ls->value) < nbr)
			++less;
		ls = ls->next;
	}
	if (!label)
		return (less);
	else
		return (greater);
}

int		get_middle(t_lst *ls, int len)
{
	t_lst	*head;
	int		less;
	int		greater;
	int		ret;
	int		c;

	head = ls;
	c = len;
	ret = 0;
	while (ls && c--)
	{
		less = compare(head, len, *(int*)(ls->value), 0);
		greater = compare(head, len, *(int*)(ls->value), 1);
		if (!(len % 2) && greater == less + 1)
			ret = *(int*)(ls->value);
		else if (len % 2 && greater == less)
			ret = *(int*)(ls->value);
		ls = ls->next;
	}
	return (ret);
}

_Bool	is_reversed(t_lst *ls)
{
	t_lst	*mid;
	int		add1;
	int		add2;
	int		n;

	add1 = 0;
	add2 = 0;
	mid = lstn(ls, lst_len(ls) / 2);
	n = lst_len(ls) / 2;
	while (n--)
	{
		add1 += *(int*)(ls->value);
		ls = ls->next;
	}
	while (ls)
	{
		add2 += *(int*)(ls->value);
		ls = ls->next;
	}
	if (add1 > add2 && ran_sort(mid, lst_len(mid), 0) >\
						(int)((double)lst_len(mid) + 0.75))
		return (1);
	return (0);
}
