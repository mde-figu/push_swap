/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   un_opers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:29:37 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/17 15:18:14 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	un_push(t_lst **dst, t_lst **src)
{
	t_lst	*tmp;

	if (src && *src)
	{
		tmp = (*src)->next;
		ft_lstadd(dst, *src);
		*src = tmp;
	}
}

void	un_swap(t_lst **head)
{
	t_lst		*tmp_swap;

	if (head && *head && (*head)->next)
	{
		tmp_swap = (*head)->next;
		(*head)->next = tmp_swap->next;
		tmp_swap->next = *head;
		*head = tmp_swap;
	}
}

static t_lst	*prelast_elem(t_lst *lst)
{
	if (lst && lst->next)
		while (lst->next->next)
			lst = lst->next;
	return (lst);
}

void	un_rotate(t_lst **head)
{
	t_lst		*tmp_first;
	t_lst		*tmp_tail;

	if (head && *head && (*head)->next)
	{
		tmp_tail = prelast_elem(*head)->next;
		tmp_first = *head;
		*head = tmp_first->next;
		tmp_tail->next = tmp_first;
		tmp_first->next = 0;
	}
}

void	un_rev_rotate(t_lst **head)
{
	t_lst	*tmp_prelast;

	if (head && *head && (*head)->next)
	{
		tmp_prelast = prelast_elem(*head);
		tmp_prelast->next->next = *head;
		*head = tmp_prelast->next;
		tmp_prelast->next = 0;
	}
}
