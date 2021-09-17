/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:09:56 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/17 15:22:24 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(char **tmp, t_lst **l_a)
{
	t_lst	*head;
	void	*val;

	val = ft_memalloc(sizeof(int));
	if (!val)
		ft_error_memory();
	head = 0;
	while (*tmp)
	{
		*((int *)val) = ft_atoi(*tmp++);
		ft_lstadd(&head, new_lst(val, sizeof(int)));
	}
	free(val);
	*l_a = 0;
	while (head)
		un_push(l_a, &head);
}

static void	*memfree(t_lst *ls)
{
	free(ls);
	return (0);
}

t_lst	*new_lst(const void *val, size_t value_size)
{
	t_lst	*ls;

	ls = (t_lst *)malloc(sizeof(t_lst));
	if (!ls)
		return (0);
	ls->next = 0;
	if (!val)
	{
		ls->value = 0;
		ls->value_size = 0;
	}
	else
	{
		ls->value_size = value_size;
		ls->value = malloc(ls->value_size);
		if (!ls->value)
			return ((t_lst *)memfree(ls));
		ft_bzero(ls->value, ls->value_size);
		ft_memcpy(ls->value, val, ls->value_size);
	}
	return (ls);
}
