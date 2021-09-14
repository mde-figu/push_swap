/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:36:11 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/13 21:06:48 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*lstn(t_lst *ls, size_t n)
{
	if (!ls)
		return (0);
	if (n > 1 && ls->next)
		return (lstn(ls->next, n - 1));
	else if (n <= 1)
		return (ls);
	else
		return (0);
}

void	ft_lstadd(t_lst **alst, t_lst *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
